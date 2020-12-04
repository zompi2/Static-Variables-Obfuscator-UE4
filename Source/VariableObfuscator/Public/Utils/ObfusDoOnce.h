#pragma once

#include "CoreMinimal.h"

struct FObfusDoOnce
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