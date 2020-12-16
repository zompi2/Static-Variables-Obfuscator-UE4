#pragma once

#include "CoreMinimal.h"
#include "VarOb.h"
#include "VarObDoOnce.h"
#include "ObfusLinearColor.generated.h"

USTRUCT(BlueprintType, Category = "Variable Obfuscator")
struct FObfusLinearColor
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	FLinearColor InitVal;

	FLinearColor GetVal()
	{
		DoOnce.Do([this]() { Val = InitVal; });
		return Val;
	}

	void SetVal(FLinearColor NewVal)
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

	TVarOb<FLinearColor> Val;
	FVarObDoOnce DoOnce;
};
