#pragma once

/**
 * This struct defines a chunk of data that will be obfuscated later.
 * N is a size of a chunk. 
 * Chunk of size 1 is a 4 bytes chunk, chunk of size 2 is a 8 bytes chunk etc. 
 */

#include "CoreMinimal.h"

template<int N>
struct FChunkN
{
    uint32 Data[N];

    FChunkN<N> operator^(const FChunkN<N>& Rhs)
    {
        FChunkN<N> Tmp;
        for (int32 I = 0; I < N; I++)
        {
            Tmp.Data[I] = Data[I] ^ Rhs.Data[I];
        }
        return Tmp;
    }

    FChunkN<N> operator^(const int32& Rhs)
    {
        FChunkN<N> Tmp;
        for (int32 I = 0; I < N; I++)
        {
            Tmp.Data[I] = Data[I] ^ Rhs;
        }
        return Tmp;
    }

    FChunkN<N>& operator^=(const FChunkN<N>& Rhs)
    {
        for (int32 I = 0; I < N; I++)
        {
            Data[I] ^= Rhs.Data[I];
        }
        return *this;
    }

    bool operator==(const FChunkN<N>& Rhs)
    {
        for (int32 I = 0; I < N; I++)
        {
            if (Data[I] != Rhs.Data[I])
            {
                return false;
            }
        }
        return true;
    }

    void GenRand()
    {
        for (int32 I = 0; I < N; I++)
        {
            Data[I] = static_cast<uint32>(FMath::RandHelper(0x7fff));
        }
    }
};
