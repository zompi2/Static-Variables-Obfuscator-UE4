#pragma once

#include "CoreMinimal.h"
#include "VarOb.h"
#include "VarObDoOnce.h"
#include "ObfusVector2D.generated.h"

USTRUCT(BlueprintType, Category = "Variable Obfuscator")
struct FObfusVector2D
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	FVector2D InitVal;

	FVector2D GetVal()
	{
		DoOnce.Do([this]() { Val = InitVal; });
		return Val;
	}

	void SetVal(FVector2D NewVal)
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

	TVarOb<FVector2D> Val;
	FVarObDoOnce DoOnce;
};
