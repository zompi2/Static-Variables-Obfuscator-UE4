#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPTypes/ObfusInt32.h"
#include "VarObBPLib.generated.h"

UCLASS()
class VARIABLEOBFUSCATOR_API UVarOBBPLib : public UBlueprintFunctionLibrary 
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure)
	static int32 GetInt32(UPARAM(Ref) FObfusInt32& ObfusInt32);

	UFUNCTION(BlueprintCallable)
	static void SetInt32(UPARAM(Ref)FObfusInt32& ObfusInt32, int32 NewValue);
};