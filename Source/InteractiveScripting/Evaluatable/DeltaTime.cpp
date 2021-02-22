// Fill out your copyright notice in the Description page of Project Settings.
#include "DeltaTime.h"
#include <InteractiveScripting/BlockManager.h>

bool ADeltaTime::HasVarManager()
{
	if (varManager->IsValidLowLevel())
	{
		return true;
	}
	else
	{
		varManager = nullptr;
		AActor* owner = GetOwner();
		if (owner->IsA<ABlockManager>())
		{
			ABlockManager* blockManager = (ABlockManager*)owner;
			varManager = blockManager->GetVarManager();

			if (varManager->IsValidLowLevel())
			{
				return true;
			}
			else
			{
				varManager = nullptr;
				return false;
			}
		}
		else
		{
			return false;
		}
	}
}

float ADeltaTime::Evaluate()
{
	if (HasVarManager())
		return varManager->GetNumber(Variables::DeltaTime);
	else
		return NULL;
}