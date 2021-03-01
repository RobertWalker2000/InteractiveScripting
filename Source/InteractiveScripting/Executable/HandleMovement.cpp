// Fill out your copyright notice in the Description page of Project Settings.
#include "HandleMovement.h"

AHandleMovement::AHandleMovement()
{
	up = EKeys::W;
	down = EKeys::S;
	left = EKeys::A;
	right = EKeys::D;
}

AExecutable::ExecuteResult AHandleMovement::Execute()
{
	if (!moveSpeed->IsValidLowLevel())
	{
		moveSpeed = nullptr;
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
		DoMovementControls();

	if (nextLine == nullptr)
		return EndReached;
	else
		return nextLine->Execute();
}

bool AHandleMovement::HasPlayerController()
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

bool AHandleMovement::HasVarManager()
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

void AHandleMovement::DoMovementControls()
{
	float moveDist = moveSpeed->Evaluate() * deltaTime->Evaluate();

	if (controller->IsInputKeyDown(up))
	{
		float posY = varManager->GetNumber(Variables::PositionY);
		posY -= moveDist;
		varManager->SetNumber(Variables::PositionY, posY);
	}

	if (controller->IsInputKeyDown(down))
	{
		float posY = varManager->GetNumber(Variables::PositionY);
		posY += moveDist;
		varManager->SetNumber(Variables::PositionY, posY);
	}

	if (controller->IsInputKeyDown(left))
	{
		float posX = varManager->GetNumber(Variables::PositionX);
		posX -= moveDist;
		varManager->SetNumber(Variables::PositionX, posX);
	}

	if (controller->IsInputKeyDown(right))
	{
		float posX = varManager->GetNumber(Variables::PositionX);
		posX += moveDist;
		varManager->SetNumber(Variables::PositionX, posX);
	}
}

void AHandleMovement::SetMoveSpeedAsSlot(AConnectionManager* connectionManager)
{
	connectionManager->AssignNumSlot(&moveSpeed);
}

void AHandleMovement::SetDeltaTimeAsSlot(AConnectionManager* connectionManager)
{
	connectionManager->AssignNumSlot(&deltaTime);
}