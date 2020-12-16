#pragma once

#include "CoreMinimal.h"
#include "VarOb.h"
#include "VarObDoOnce.h"
#include "ObfusTransform.generated.h"

USTRUCT(BlueprintType, Category = "Variable Obfuscator")
struct FObfusTransform
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	FTransform InitVal;

	FTransform GetVal()
	{
		DoOnce.Do([this]() { Val = InitVal; });
		return Val;
	}

	void SetVal(FTransform NewVal)
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

	TVarOb<FTransform> Val;
	FVarObDoOnce DoOnce;
};
