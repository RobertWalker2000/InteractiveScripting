// Fill out your copyright notice in the Description page of Project Settings.
#include "NumVar.h"

ANumVar::ANumVar()
{
	varName = PositionX;
}

float ANumVar::Evaluate()
{
	if (HasVarManager())
		return varManager->GetNumber(varName);
	else
		return NULL;
}

void ANumVar::SetValue(float val)
{
	if (HasVarManager())
		varManager->SetNumber(varName, val);
}

void ANumVar::SetVariableName(FString nameIn)
{
	varName = UVariableManager::GetVarEnum(nameIn);
}

bool ANumVar::HasVarManager()
{
	if (varManager->IsValidLowLevel())
	{
		return true;
	}
	else
	{
		AActor* owner = GetAttachParentActor();
		if (owner->IsA<ABlockManager>())
		{
			blockManager = (ABlockManager*)owner;
			varManager = blockManager->GetVarManager();

			//Check to ensure we found the variable manager
			if (varManager->IsValidLowLevel())
				return true;
		}
	}

	return false;
}

void ANumVar::SetAsNumVarValue(AConnectionManager* connectionManager)
{
	connectionManager->AssignNumVarVal(this, this);
}
