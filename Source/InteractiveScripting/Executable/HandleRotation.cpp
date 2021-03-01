// Fill out your copyright notice in the Description page of Project Settings.
#include "HandleRotation.h"

AHandleRotation::AHandleRotation()
{
	rotLeft = EKeys::Q;
	rotRight = EKeys::E;
}

AExecutable::ExecuteResult AHandleRotation::Execute()
{
	if (!rotationSpeed->IsValidLowLevel())
	{
		rotationSpeed = nullptr;
		return MissingComponent;
	}

	if (!deltaTime->IsValidLowLevel())
	{
		deltaTime = nullptr;
		return MissingComponent;
	}

	if (!nextLine->IsValidLowLevel())
	{
		nextLine = nullptr;
	}

	if (HasPlayerController() && HasVarManager())
		DoRotationControls();

	if (nextLine == nullptr)
		return EndReached;
	else
		return nextLine->Execute();
}

bool AHandleRotation::HasPlayerController()
{
	if (controller->IsValidLowLevel())
	{
		return true;
	}
	else
	{
		controller = GetWorld()->GetFirstPlayerController();

		if (controller->IsValidLowLevel())
		{
			return true;
		}
		else
		{
			controller = nullptr;
			return false;
		}
	}
}

bool AHandleRotation::HasVarManager()
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
			ABlockManager* blockManager = (ABlockManager*)owner;
			varManager = blockManager->GetVarManager();

			//Check to ensure we found the variable manager
			if (varManager->IsValidLowLevel())
				return true;
		}
	}

	return false;
}

void AHandleRotation::DoRotationControls()
{
	float rotAmount = rotationSpeed->Evaluate() * deltaTime->Evaluate();

	if (controller->IsInputKeyDown(rotLeft))
	{
		float rotation = varManager->GetNumber(Variables::Rotation);
		rotation -= rotAmount;
		varManager->SetNumber(Variables::Rotation, rotation);
	}

	if (controller->IsInputKeyDown(rotRight))
	{
		float rotation = varManager->GetNumber(Variables::Rotation);
		rotation += rotAmount;
		varManager->SetNumber(Variables::Rotation, rotation);
	}

}

void AHandleRotation::SetRotationSpeedAsSlot(AConnectionManager* connectionManager)
{
	connectionManager->AssignNumSlot(&rotationSpeed);
}

void AHandleRotation::SetDeltaTimeAsSlot(AConnectionManager* connectionManager)
{
	connectionManager->AssignNumSlot(&deltaTime);
}