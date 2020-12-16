#pragma once

#include "CoreMinimal.h"
#include "VarOb.h"
#include "VarObDoOnce.h"
#include "ObfusByte.generated.h"

USTRUCT(BlueprintType, Category = "Variable Obfuscator")
struct FObfusByte
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	uint8 InitVal;

	uint8 GetVal()
	{
		DoOnce.Do([this]() { Val = InitVal; });
		return Val;
	}

	void SetVal(uint8 NewVal)
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

	TVarOb<uint8> Val;
	FVarObDoOnce DoOnce;
};
