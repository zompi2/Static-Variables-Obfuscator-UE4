#pragma once

#include "CoreMinimal.h"
#include "VarOb.h"
#include "VarObDoOnce.h"
#include "ObfusVector.generated.h"

USTRUCT(BlueprintType, Category = "Variable Obfuscator")
struct FObfusVector
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	FVector InitVal;

	FVector GetVal()
	{
		DoOnce.Do([this]() { Val = InitVal; });
		return Val;
	}

	void SetVal(FVector NewVal)
	{
		DoOnce.DoEmpty();
		Val = NewVal;
	}

	void ToArray(TArray<uint8>& OutData)
	{
		Val.ToArray(OutData);
	}

	void FromArray(const TArray<uint8>& InData)
	{
		Val.FromArray(InData);
	}

private:

	TVarOb<FVector> Val;
	FVarObDoOnce DoOnce;
};
