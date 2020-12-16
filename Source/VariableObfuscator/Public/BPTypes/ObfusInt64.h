#pragma once

#include "CoreMinimal.h"
#include "VarOb.h"
#include "VarObDoOnce.h"
#include "ObfusInt64.generated.h"

USTRUCT(BlueprintType, Category = "Variable Obfuscator")
struct FObfusInt64
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	int64 InitVal;

	int64 GetVal()
	{
		DoOnce.Do([this]() { Val = InitVal; });
		return Val;
	}

	void SetVal(int64 NewVal)
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

	TVarOb<int64> Val;
	FVarObDoOnce DoOnce;
};
