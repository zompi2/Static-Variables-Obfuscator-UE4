#pragma once

#include "CoreMinimal.h"
#include "VarOb.h"
#include "VarObDoOnce.h"
#include "ObfusFloat.generated.h"

USTRUCT(BlueprintType, Category = "Variable Obfuscator")
struct FObfusFloat
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	float InitVal;

	float GetVal()
	{
		DoOnce.Do([this]() { Val = InitVal; });
		return Val;
	}

	void SetVal(float NewVal)
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

	TVarOb<float> Val;
	FVarObDoOnce DoOnce;
};
