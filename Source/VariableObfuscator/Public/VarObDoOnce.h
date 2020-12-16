#pragma once

/**
 * Small, helper struct to ensue the function will perform only once.
 */

#include "CoreMinimal.h"

struct FVarObDoOnce
{

public:

	void Do(const TFunction<void()>& Action)
	{
		if (bDone == false)
		{
			bDone = true;
			Action();
		}
	}

	void DoEmpty()
	{
		bDone = true;
	}

private:

	bool bDone = false;
};