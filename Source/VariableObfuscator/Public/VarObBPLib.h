#pragma once

/**
 * This is a BP library to somehow handle obfuscation in BP.
 */

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "BPTypes/ObfusBool.h"
#include "BPTypes/ObfusByte.h"
#include "BPTypes/ObfusInt32.h"
#include "BPTypes/ObfusInt64.h"
#include "BPTypes/ObfusFloat.h"

#include "BPTypes/ObfusTransform.h"
#include "BPTypes/ObfusVector.h"
#include "BPTypes/ObfusVector2D.h"
#include "BPTypes/ObfusRotator.h"
#include "BPTypes/ObfusQuat.h"

#include "BPTypes/ObfusColor.h"
#include "BPTypes/ObfusLinearColor.h"

#include "VarObBPLib.generated.h"

UCLASS()
class VARIABLEOBFUSCATOR_API UVarOBBPLib : public UBlueprintFunctionLibrary 
{
	GENERATED_BODY()

public:

	// BOOL
	UFUNCTION(BlueprintPure, Category = "Variable Obfuscator")
	static bool GetBool(UPARAM(Ref) FObfusBool& ObfusBool);

	UFUNCTION(BlueprintCallable, Category = "Variable Obfuscator")
	static void SetBool(UPARAM(Ref) FObfusBool& ObfusBool, bool NewValue);

	// BYTE
	UFUNCTION(BlueprintPure, Category = "Variable Obfuscator")
	static uint8 GetByte(UPARAM(Ref) FObfusByte& ObfusByte);

	UFUNCTION(BlueprintCallable, Category = "Variable Obfuscator")
	static void SetByte(UPARAM(Ref) FObfusByte& ObfusByte, uint8 NewValue);

	// INT32
	UFUNCTION(BlueprintPure, Category = "Variable Obfuscator")
	static int32 GetInt32(UPARAM(Ref) FObfusInt32& ObfusInt32);

	UFUNCTION(BlueprintCallable, Category = "Variable Obfuscator")
	static void SetInt32(UPARAM(Ref) FObfusInt32& ObfusInt32, int32 NewValue);

	// INT64
	UFUNCTION(BlueprintPure, Category = "Variable Obfuscator")
	static int64 GetInt64(UPARAM(Ref) FObfusInt64& ObfusInt64);

	UFUNCTION(BlueprintCallable, Category = "Variable Obfuscator")
	static void SetInt64(UPARAM(Ref) FObfusInt64& ObfusInt64, int64 NewValue);

	// FLOAT
	UFUNCTION(BlueprintPure, Category = "Variable Obfuscator")
	static float GetFloat(UPARAM(Ref) FObfusFloat& ObfusFloat);

	UFUNCTION(BlueprintCallable, Category = "Variable Obfuscator")
	static void SetFloat(UPARAM(Ref) FObfusFloat& ObfusFloat, float NewValue);

	// TRANSFORM
	UFUNCTION(BlueprintPure, Category = "Variable Obfuscator")
	static FTransform GetTransform(UPARAM(Ref) FObfusTransform& ObfusTransform);

	UFUNCTION(BlueprintCallable, Category = "Variable Obfuscator")
	static void SetTransform(UPARAM(Ref) FObfusTransform& ObfusTransform, FTransform NewValue);

	// VECTOR
	UFUNCTION(BlueprintPure, Category = "Variable Obfuscator")
	static FVector GetVector(UPARAM(Ref) FObfusVector& ObfusVector);

	UFUNCTION(BlueprintCallable, Category = "Variable Obfuscator")
	static void SetVector(UPARAM(Ref) FObfusVector& ObfusVector, FVector NewValue);

	// VECTOR2D
	UFUNCTION(BlueprintPure, Category = "Variable Obfuscator")
	static FVector2D GetVector2D(UPARAM(Ref) FObfusVector2D& ObfusVector2D);

	UFUNCTION(BlueprintCallable, Category = "Variable Obfuscator")
	static void SetVector2D(UPARAM(Ref) FObfusVector2D& ObfusVector2D, FVector2D NewValue);

	// ROTATOR
	UFUNCTION(BlueprintPure, Category = "Variable Obfuscator")
	static FRotator GetRotator(UPARAM(Ref) FObfusRotator& ObfusRotator);

	UFUNCTION(BlueprintCallable, Category = "Variable Obfuscator")
	static void SetRotator(UPARAM(Ref) FObfusRotator& ObfusRotator, FRotator NewValue);

	// QUAT
	UFUNCTION(BlueprintPure, Category = "Variable Obfuscator")
	static FQuat GetQuat(UPARAM(Ref) FObfusQuat& ObfusQuat);

	UFUNCTION(BlueprintCallable, Category = "Variable Obfuscator")
	static void SetQuat(UPARAM(Ref) FObfusQuat& ObfusQuat, FQuat NewValue);

	// COLOR
	UFUNCTION(BlueprintPure, Category = "Variable Obfuscator")
	static FColor GetColor(UPARAM(Ref) FObfusColor& ObfusColor);

	UFUNCTION(BlueprintCallable, Category = "Variable Obfuscator")
	static void SetColor(UPARAM(Ref) FObfusColor& ObfusColor, FColor NewValue);

	// LINEARCOLOR
	UFUNCTION(BlueprintPure, Category = "Variable Obfuscator")
	static FLinearColor GetLinearColor(UPARAM(Ref) FObfusLinearColor& ObfusLinearColor);

	UFUNCTION(BlueprintCallable, Category = "Variable Obfuscator")
	static void SetLinearColor(UPARAM(Ref) FObfusLinearColor& ObfusLinearColor, FLinearColor NewValue);
};