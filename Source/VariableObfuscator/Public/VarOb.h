#pragma once

/**
 * This is the core of the obfuscator. 
 * To obfuscate a static data declare it as in example: TVarOb<int32>.
 */

#include "CoreMinimal.h"
#include "VarObChunk.h"
#include "VarObDelegates.h"
#include "VarObSupportedTypes.h"

#define VO_VAL 0
#define VO_KEY 1
#define VO_CHK 2

template<typename T>
class TVarOb
{
    using FChunkX = FChunkN<(sizeof(T)-1)/4+1>;

private:

    FChunkX Data[3] = {};

    inline void MemMangle()
    {
        if (uint8* DataPtr = reinterpret_cast<uint8*>(Data))
        {
            for (uint8 I = 0; I < sizeof(FChunkX) * 3; I += 3)
            {
                uint8 Tmp = DataPtr[I];
                DataPtr[I] = DataPtr[I + 2];
                DataPtr[I + 2] = Tmp;
            }
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

    TVarOb(T V = T())
    {
        static_assert(TVarObSupportedType<T>::Value, "Unsupported Type");

        Data[VO_KEY].GenRand();
        Data[VO_VAL] = *(FChunkX*)&V;
        Data[VO_CHK] = (Data[VO_VAL] ^ VO_MASK);

        Data[VO_VAL] ^= Data[VO_KEY];
        MemMangle();
    }

    TVarOb(TVarOb& V)
    {
        FMemory::Memcpy(Data, V.Data, sizeof(FChunkX) * 3);
    }

    TVarOb& operator=(T& V)
    {
        static_assert(TVarObSupportedType<T>::Value, "Unsupported Type");

        Data[VO_KEY].GenRand();
        Data[VO_VAL] = *(FChunkX*)&V;
        Data[VO_CHK] = (Data[VO_VAL] ^ VO_MASK);

        Data[VO_VAL] ^= Data[VO_KEY];
        MemMangle();

        return *this;
    }

    operator T()
    {
        MemMangle();
        FChunkX Tmp = Data[VO_VAL] ^ Data[VO_KEY];
        Check(Tmp == (Data[VO_CHK] ^ VO_MASK));
        MemMangle();
        return *(T*)&Tmp;
    }

    void ToArray(TArray<uint8>& OutData)
    {
        OutData.SetNum(sizeof(FChunkX) * 3);
        FMemory::Memcpy(OutData.GetData(), Data, sizeof(FChunkX) * 3);
    }

    void FromArray(const TArray<uint8>& InData)
    {
        checkf(InData.Num() == sizeof(FChunkX) * 3, TEXT("Bad size of imported array (expected %i bytes but received %i bytes"), sizeof(FChunkX) * 3, InData.Num());
        FMemory::Memcpy(Data, InData.GetData(), sizeof(FChunkX) * 3);
    }

#define VO_BINARY_OP(_op)   TVarOb& operator _op (const T& Rhs)                         \
                            {                                                           \
                                MemMangle();                                            \
                                FChunkX Tmp = Data[VO_VAL] ^ Data[VO_KEY];              \
                                Check(Tmp == (Data[VO_CHK] ^ VO_MASK));                 \
                                T Res = *(T*)&Tmp;                                      \
                                Res _op Rhs;                                            \
                                Data[VO_KEY].GenRand();                                 \
                                Data[VO_VAL] = *(FChunkX*)&Res;                         \
                                Data[VO_CHK] = (Data[VO_VAL] ^ VO_MASK);                \
                                Data[VO_VAL] ^= Data[VO_KEY];                           \
                                MemMangle();                                            \
                                return *this;                                           \
                            }                                                           \

#define VO_UNARY_OP(_op)    TVarOb& operator _op ()                                     \
                            {                                                           \
                                MemMangle();                                            \
                                FChunkX Tmp = Data[VO_VAL] ^ Data[VO_KEY];              \
                                Check(Tmp == (Data[VO_CHK] ^ VO_MASK));                 \
                                T V = *(T*)&Tmp;                                        \
                                v _op;                                                  \
                                Data[VO_KEY].GenRand();                                 \
                                Data[VO_VAL] = *(FChunkX*)&V;                           \
                                Data[VO_CHK] = (Data[VO_VAL] ^ VO_MASK);                \
                                Data[VO_VAL] ^= Data[VO_KEY];                           \
                                MemMangle();                                            \
                                return *this;                                           \
                            }                                                           \
                            TVarOb operator _op (int)                                   \
                            {                                                           \
                                TVarOb Tmp(*this);                                      \
                                operator _op();                                         \
                                return Tmp;                                             \
                            }                                                           \

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
