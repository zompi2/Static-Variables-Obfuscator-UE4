#pragma once

/**
 * This is a delegate which will broadcast warning about possible
 * memory breach. 
 */

#include "CoreMinimal.h"

class VARIABLEOBFUSCATOR_API FVarObDelegates
{

public:

	DECLARE_MULTICAST_DELEGATE(FOnVariableCheatDetected);
	static FOnVariableCheatDetected OnVariableCheatDetected;
};