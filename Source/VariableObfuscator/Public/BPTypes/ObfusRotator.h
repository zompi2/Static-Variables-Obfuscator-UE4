#pragma once

#include "CoreMinimal.h"
#include "VarOb.h"
#include "VarObDoOnce.h"
#include "ObfusRotator.generated.h"

USTRUCT(BlueprintType, Category = "Variable Obfuscator")
struct FObfusRotator
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	FRotator InitVal;

	FRotator GetVal()
	{
		DoOnce.Do([this]() { Val = InitVal; });
		return Val;
	}

	void SetVal(FRotator NewVal)
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

	TVarOb<FRotator> Val;
	FVarObDoOnce DoOnce;
};
