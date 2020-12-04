#pragma once

#include "CoreMinimal.h"
#include "VarOb.h"
#include "Utils/ObfusDoOnce.h"
#include "ObfusInt32.generated.h"

USTRUCT(BlueprintType)
struct FObfusInt32
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	int32 InitVal = 0;

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

private:

	TVarOb<int32> Val;
	FObfusDoOnce DoOnce;
};