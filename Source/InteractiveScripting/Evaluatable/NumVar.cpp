// Fill out your copyright notice in the Description page of Project Settings.
#include "NumVar.h"

UNumVar::UNumVar()
{
	isVariable = true;
}

//TODO: Create a generic system so that the variable class can be used for multiple variables, not just this one
float UNumVar::Evaluate()
{
	if (FindVarManager())
		return varManager->GetPositionX();
	else
		return 0;
}

void UNumVar::SetValue(float val)
{
	if (FindVarManager())
		varManager->SetPositionX(val);
}

bool UNumVar::FindVarManager()
{
	//If we don't have a pointer to varManager, try and get one. Otherwise, just return true
	if (varManager == nullptr)
	{
		AActor* owner = GetOwner();
		AActor* master = owner->GetAttachParentActor();
		blockManager = (UBlockManager*)master->GetComponentByClass(UBlockManager::StaticClass());
		varManager = blockManager->GetVarManager();

		//Check to ensure we found the variable manager
		if (varManager == nullptr)
			return false;
		else 
			return true;
	}
	else
		return true;
}
