// Fill out your copyright notice in the Description page of Project Settings.
#include "Shoot.h"
#include "InteractiveScripting/Blockmanager.h"
#include "InteractiveScripting/VariableManager.h"
#include "InteractiveScripting/Projectile.h"
#include "InteractiveScripting/Evaluatable/Vector2.h"
#include "InteractiveScripting/Evaluatable/Number.h"

AShoot::AShoot()
{

}

AExecutable::ExecuteResult AShoot::Execute()
{
	if (!nextLine->IsValidLowLevel())
	{
		nextLine = nullptr;
	}

	if (!vectorIn->IsValidLowLevel())
	{
		vectorIn = nullptr;
		return MissingComponent;
	}

	if (!rotationIn->IsValidLowLevel())
	{
		rotationIn = nullptr;
		return MissingComponent;
	}

	//Get all the necessary variables. These will be replaced by inputs after testing
	if (HasVarManager())
	{
		//Use a timer in varManager to prevent multiple shots being fired too quickly, regardless of the number of Shoot blocks in use
		if (varManager->GetNumber(Variables::ShootTimer) <= 0.0f)
		{
			FMyVector pos = vectorIn->Evaluate();
			float rotation = rotationIn->Evaluate();

			FTransform spawnTransform = FTransform::Identity;

			FVector ballPos = FVector(pos.x, pos.y, spawnHeight);

			//Create a vector representing the forward vector of the player based on the inputs
			FVector direction = FVector::ForwardVector;
			direction = direction.RotateAngleAxis(rotation, FVector::UpVector);
			direction.Normalize();

			//Move the spawn position along the forward vector a small amount to ensure it is outside the player
			ballPos += (direction * offsetDist);
			spawnTransform.SetTranslation(ballPos);

			FVector ballVel = direction * speed;
			AProjectile* projectile = GetWorld()->SpawnActor<AProjectile>(AProjectile::StaticClass(), spawnTransform);
			projectile->ballMesh->AddImpulse(ballVel, FName(), true);

			//Reset the timer after shooting
			varManager->SetNumber(Variables::ShootTimer, maxTimer);
		}
	}

	if (nextLine == nullptr)
		return EndReached;
	else
		return nextLine->Execute();
}

void AShoot::SetVectorAsSlot(AConnectionManager* connectionManager)
{
	connectionManager->AssignVectorSlot(&vectorIn);
}

void AShoot::SetRotationAsSlot(AConnectionManager* connectionManager)
{
	connectionManager->AssignNumSlot(&rotationIn);
}

bool AShoot::HasVarManager()
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