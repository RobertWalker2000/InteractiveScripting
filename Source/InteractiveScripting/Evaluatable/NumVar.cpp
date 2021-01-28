// Fill out your copyright notice in the Description page of Project Settings.
#include "NumVar.h"

ANumVar::ANumVar()
{
	isVariable = true;
	varName = NoValue;
}

//TODO: Create a generic system so that the variable class can be used for multiple variables, not just this one
float ANumVar::Evaluate()
{
	if (HasVarType())
		return varManager->GetNumber(varName);
	else
		return 0;
}

void ANumVar::SetValue(float val)
{
	if (HasVarType())
		varManager->SetNumber(varName, val);
}

bool ANumVar::HasVarType()
{

	//If we don't have a variable type, try to get one. Otherwise return true
	if (varName == NoValue)
	{
		AActor* owner = GetOwner();
		AActor* master = owner->GetAttachParentActor();
		blockManager = (UBlockManager*)master->GetComponentByClass(UBlockManager::StaticClass());
		varManager = blockManager->GetVarManager();
		varName = UVariableManager::GetVarEnum(this->GetName());

		//Check to ensure we found the variable manager
		if (varName == NoValue)
			return false;
		else 
			return true;
	}
	else
		return true;
}
