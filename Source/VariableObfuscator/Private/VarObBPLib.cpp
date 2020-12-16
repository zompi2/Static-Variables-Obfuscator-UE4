#pragma once

#include "VarObBPLib.h"

// BOOL
bool UVarOBBPLib::GetBool(FObfusBool& ObfusBool)
{
	return ObfusBool.GetVal();
}

void UVarOBBPLib::SetBool(FObfusBool& ObfusBool, bool NewValue)
{
	ObfusBool.SetVal(NewValue);
}

// BYTE
uint8 UVarOBBPLib::GetByte(FObfusByte& ObfusByte)
{
	return ObfusByte.GetVal();
}

void UVarOBBPLib::SetByte(FObfusByte& ObfusByte, uint8 NewValue)
{
	ObfusByte.SetVal(NewValue);
}

// INT32
int32 UVarOBBPLib::GetInt32(FObfusInt32& ObfusInt32)
{
	return ObfusInt32.GetVal();
}

void UVarOBBPLib::SetInt32(FObfusInt32& ObfusInt32, int32 NewValue)
{
	ObfusInt32.SetVal(NewValue);
}

// INT64
int64 UVarOBBPLib::GetInt64(FObfusInt64& ObfusInt64)
{
	return ObfusInt64.GetVal();
}

void UVarOBBPLib::SetInt64(FObfusInt64& ObfusInt64, int64 NewValue)
{
	ObfusInt64.SetVal(NewValue);
}

// FLOAT
float UVarOBBPLib::GetFloat(FObfusFloat& ObfusFloat)
{
	return ObfusFloat.GetVal();
}

void UVarOBBPLib::SetFloat(FObfusFloat& ObfusFloat, float NewValue)
{
	ObfusFloat.SetVal(NewValue);
}

// TRANSFORM
FTransform UVarOBBPLib::GetTransform(FObfusTransform& ObfusTransform)
{
	return ObfusTransform.GetVal();
}

void UVarOBBPLib::SetTransform(FObfusTransform& ObfusTransform, FTransform NewValue)
{
	ObfusTransform.SetVal(NewValue);
}

// VECTOR
FVector UVarOBBPLib::GetVector(FObfusVector& ObfusVector)
{
	return ObfusVector.GetVal();
}

void UVarOBBPLib::SetVector(FObfusVector& ObfusVector, FVector NewValue)
{
	ObfusVector.SetVal(NewValue);
}

// VECTOR2D
FVector2D UVarOBBPLib::GetVector2D(FObfusVector2D& ObfusVector2D)
{
	return ObfusVector2D.GetVal();
}

void UVarOBBPLib::SetVector2D(FObfusVector2D& ObfusVector2D, FVector2D NewValue)
{
	ObfusVector2D.SetVal(NewValue);
}

// ROTATOR
FRotator UVarOBBPLib::GetRotator(FObfusRotator& ObfusRotator)
{
	return ObfusRotator.GetVal();
}

void UVarOBBPLib::SetRotator(FObfusRotator& ObfusRotator, FRotator NewValue)
{
	ObfusRotator.SetVal(NewValue);
}

// QUAT
FQuat UVarOBBPLib::GetQuat(FObfusQuat& ObfusQuat)
{
	return ObfusQuat.GetVal();
}

void UVarOBBPLib::SetQuat(FObfusQuat& ObfusQuat, FQuat NewValue)
{
	ObfusQuat.SetVal(NewValue);
}

// COLOR
FColor UVarOBBPLib::GetColor(FObfusColor& ObfusColor)
{
	return ObfusColor.GetVal();
}

void UVarOBBPLib::SetColor(FObfusColor& ObfusColor, FColor NewValue)
{
	ObfusColor.SetVal(NewValue);
}

// LINEARCOLOR
FLinearColor UVarOBBPLib::GetLinearColor(FObfusLinearColor& ObfusLinearColor)
{
	return ObfusLinearColor.GetVal();
}

void UVarOBBPLib::SetLinearColor(FObfusLinearColor& ObfusLinearColor, FLinearColor NewValue)
{
	ObfusLinearColor.SetVal(NewValue);
}
