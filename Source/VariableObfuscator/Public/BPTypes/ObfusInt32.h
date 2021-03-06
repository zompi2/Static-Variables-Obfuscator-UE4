#pragma once

#include "CoreMinimal.h"
#include "VarOb.h"
#include "VarObDoOnce.h"
#include "ObfusInt32.generated.h"

USTRUCT(BlueprintType, Category = "Variable Obfuscator")
struct FObfusInt32
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	int32 InitVal;

	int32 GetVal()
	{
		DoOnce.Do([this]() { Val = InitVal; });
		return Val;
	}

	void SetVal(int32 NewVal)
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

	TVarOb<int32> Val;
	FVarObDoOnce DoOnce;
};
