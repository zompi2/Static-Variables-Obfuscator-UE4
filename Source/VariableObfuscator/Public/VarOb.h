#pragma once

#include "CoreMinimal.h"
#include "VarObDelegates.h"
#include "VarObTraits.h"

#define VO_VAL 0
#define VO_KEY 1
#define VO_CHK 2

template<int N>
struct ChunkN
{
	uint32 Data[N];

	ChunkN<N> operator^(const ChunkN<N>& Rhs)
	{
		ChunkN<N> tmp;
		for (int i = 0; i < N; i++)
		{
			tmp.Data[i] = Data[i] ^ Rhs.Data[i];
		}
		return tmp;
	}

	ChunkN<N> operator^(const int32& Rhs)
	{
		ChunkN<N> tmp;
		for (int i = 0; i < N; i++)
		{
			tmp.Data[i] = Data[i] ^ Rhs;
		}
		return tmp;
	}

	ChunkN<N>& operator^=(const ChunkN<N>& Rhs)
	{
		for (int i = 0; i < N; i++)
		{
			Data[i] ^= Rhs.Data[i];
		}
		return *this;
	}

	bool operator==(const ChunkN<N>& Rhs)
	{
		for (int i = 0; i < N; i++)
		{
			if (Data[i] != Rhs.Data[i])
			{
				return false;
			}
		}
		return true;
	}

	void GenRand()
	{
		for (int i = 0; i < N; i++)
		{
			Data[i] = static_cast<uint32>(FMath::RandHelper(0x7fff));
		}
	}
};

template<typename T>
class TVarOb
{
private:

	using ChunkX = ChunkN<(sizeof(T)-1)/4+1>;
	ChunkX Data[3] = {};

	inline void MemMangle()
	{
		uint8* DataPtr = reinterpret_cast<uint8*>(Data);
		for (uint8 I = 0; I < sizeof(ChunkX) * 3; I += 3)
		{
			uint8 Tmp = DataPtr[I];
			DataPtr[I] = DataPtr[I + 2];
			DataPtr[I + 2] = Tmp;
		}
	}

	inline void Check(bool bCondition)
	{
		if (bCondition == false)
		{
			FVarObDelegates::OnVariableCheatDetected.Broadcast();
		}
	}

public:

	
	TVarOb(T v = 0)
	{
		static_assert(TVarObSupportedType<T>::Value, "Unsupported Type");

		Data[VO_KEY].GenRand();
		Data[VO_VAL] = *(ChunkX*)&v;
		Data[VO_CHK] = (Data[VO_VAL] ^ VO_MASK);

		Data[VO_VAL] ^= Data[VO_KEY];
		MemMangle();
	}

	TVarOb(TVarOb& v)
	{
		FMemory::Memcpy(Data, v.Data, sizeof(ChunkX) * 3);
	}

	TVarOb& operator=(T& v)
	{
		static_assert(TVarObSupportedType<T>::Value, "Unsupported Type");

		Data[VO_KEY].GenRand();
		Data[VO_VAL] = *(ChunkX*)&v;
		Data[VO_CHK] = (Data[VO_VAL] ^ VO_MASK);

		Data[VO_VAL] ^= Data[VO_KEY];
		MemMangle();

		return *this;
	}

	operator T()
	{
		MemMangle();
		ChunkX Tmp = Data[VO_VAL] ^ Data[VO_KEY];
		Check(Tmp == (Data[VO_CHK] ^ VO_MASK));
		MemMangle();
		return *(T*)&Tmp;
	}

#define VO_BINARY_OP(_op)	TVarOb& operator _op (const T& Rhs)							\
							{															\
								MemMangle();											\
								ChunkX Tmp = Data[VO_VAL] ^ Data[VO_KEY];				\
								Check(Tmp == (Data[VO_CHK] ^ VO_MASK));					\
								T Res = *(T*)&Tmp;										\
								Res _op Rhs;											\
								Data[VO_KEY].GenRand();									\
								Data[VO_VAL] = *(ChunkX*)&Res;							\
								Data[VO_CHK] = (Data[VO_VAL] ^ VO_MASK);				\
								Data[VO_VAL] ^= Data[VO_KEY];							\
								MemMangle();											\
								return *this;											\
							}															\

#define VO_UNARY_OP(_op)	TVarOb& operator _op ()										\
							{															\
								MemMangle();											\
								ChunkX Tmp = Data[VO_VAL] ^ Data[VO_KEY];				\
								Check(Tmp == (Data[VO_CHK] ^ VO_MASK));					\
								T v = *(T*)&Tmp;										\
								v _op;													\
								Data[VO_KEY].GenRand();									\
								Data[VO_VAL] = *(ChunkX*)&v;							\
								Data[VO_CHK] = (Data[VO_VAL] ^ VO_MASK);				\
								Data[VO_VAL] ^= Data[VO_KEY];							\
								MemMangle();											\
								return *this;											\
							}															\
							TVarOb operator _op (int)									\
							{															\
								TVarOb Tmp(*this);										\
								operator _op();											\
								return Tmp;												\
							}															\

	VO_BINARY_OP(*=)
	VO_BINARY_OP(/=)
	VO_BINARY_OP(%=)
	VO_BINARY_OP(-=)
	VO_BINARY_OP(+=)
	VO_BINARY_OP(^=)
	VO_BINARY_OP(<<)
	VO_BINARY_OP(>>)

	VO_UNARY_OP(++)
	VO_UNARY_OP(--)
};