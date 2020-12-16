#pragma once

#include "CoreMinimal.h"
#include "VarOb.h"
#include "VarObDoOnce.h"
#include "ObfusBool.generated.h"

USTRUCT(BlueprintType, Category = "Variable Obfuscator")
struct FObfusBool
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	bool InitVal;

	bool GetVal()
	{
		DoOnce.Do([this]() { Val = InitVal; });
		return Val;
	}

	void SetVal(bool NewVal)
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

	TVarOb<bool> Val;
	FVarObDoOnce DoOnce;
};
