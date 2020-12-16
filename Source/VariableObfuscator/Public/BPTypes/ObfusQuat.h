#pragma once

#include "CoreMinimal.h"
#include "VarOb.h"
#include "VarObDoOnce.h"
#include "ObfusQuat.generated.h"

USTRUCT(BlueprintType, Category = "Variable Obfuscator")
struct FObfusQuat
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	FQuat InitVal;

	FQuat GetVal()
	{
		DoOnce.Do([this]() { Val = InitVal; });
		return Val;
	}

	void SetVal(FQuat NewVal)
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

	TVarOb<FQuat> Val;
	FVarObDoOnce DoOnce;
};
