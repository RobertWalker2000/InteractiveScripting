// Fill out your copyright notice in the Description page of Project Settings.
#include "NumVar.h"

ANumVar::ANumVar()
{
	isVariable = true;
	varName = NoValue;
}

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

void ANumVar::SetVariableName(FString nameIn)
{
	nameString = nameIn;
}

bool ANumVar::HasVarType()
{
	//If we don't have a variable type, try to get one. Otherwise return true
	if (varName == NoValue)
	{
		AActor* owner = GetAttachParentActor();
		if (owner->IsA<ABlockManager>())
		{
			blockManager = (ABlockManager*)owner;
			varManager = blockManager->GetVarManager();
			varName = UVariableManager::GetVarEnum(nameString);

			//Check to ensure we found the variable manager
			if (varName == NoValue)
				return false;
			else
				return true;
		}
		else
			return false;	//If the owner is not a block manager,we can't proceed
	}
	else
		return true;
}

void ANumVar::SetAsNumVarValue(AConnectionManager* connectionManager)
{
	connectionManager->AssignNumVarVal(this);
}
