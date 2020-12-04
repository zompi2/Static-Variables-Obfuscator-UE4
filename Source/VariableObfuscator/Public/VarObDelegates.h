#pragma once

#include "CoreMinimal.h"

class VARIABLEOBFUSCATOR_API FVarObDelegates
{

public:

	DECLARE_MULTICAST_DELEGATE(FOnVariableCheatDetected);
	static FOnVariableCheatDetected OnVariableCheatDetected;
};