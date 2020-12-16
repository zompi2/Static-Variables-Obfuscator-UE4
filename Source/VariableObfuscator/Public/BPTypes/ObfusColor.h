#pragma once

#include "CoreMinimal.h"
#include "VarOb.h"
#include "VarObDoOnce.h"
#include "ObfusColor.generated.h"

USTRUCT(BlueprintType, Category = "Variable Obfuscator")
struct FObfusColor
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	FColor InitVal;

	FColor GetVal()
	{
		DoOnce.Do([this]() { Val = InitVal; });
		return Val;
	}

	void SetVal(FColor NewVal)
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

	TVarOb<FColor> Val;
	FVarObDoOnce DoOnce;
};
