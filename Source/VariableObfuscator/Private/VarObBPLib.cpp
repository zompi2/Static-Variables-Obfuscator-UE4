#pragma once

#include "VarObBPLib.h"

int32 UVarOBBPLib::GetInt32(FObfusInt32& ObfusInt32)
{
	return ObfusInt32.GetVal();
}

void UVarOBBPLib::SetInt32(FObfusInt32& ObfusInt32, int32 NewValue)
{
	ObfusInt32.SetVal(NewValue);
}
