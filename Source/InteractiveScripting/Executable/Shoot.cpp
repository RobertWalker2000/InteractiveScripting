// Fill out your copyright notice in the Description page of Project Settings.
#include "Shoot.h"
#include "InteractiveScripting/Blockmanager.h"
#include "InteractiveScripting/Projectile.h"

AShoot::AShoot()
{

}

AExecutable::ExecuteResult AShoot::Execute()
{
	if (!nextLine->IsValidLowLevel())
	{
		nextLine = nullptr;
	}

	//Get all the necessary variables. These will be replaced by inputs after testing
	if (HasVarManager())
	{
		//Use a timer in varManager to prevent multiple shots being fired too quickly, regardless of the number of Shoot blocks in use
		if (varManager->GetNumber(Variables::ShootTimer) <= 0.0f)
		{
			positionX = varManager->GetNumber(Variables::PositionX);
			positionY = varManager->GetNumber(Variables::PositionY);
			rotation = varManager->GetNumber(Variables::Rotation);
			speed = 60.0f;

			FTransform spawnTransform = FTransform::Identity;

			FVector position = FVector(positionX, positionY, 70.0f);

			//Create a vector representing the forward vector of the player based on the inputs
			FVector direction = FVector::ForwardVector;
			direction = direction.RotateAngleAxis(rotation, FVector::UpVector);
			direction.Normalize();

			//Move the spawn position along the forward vector a small amount to ensure it is outside the player
			position += (direction * 100.0f);
			spawnTransform.SetTranslation(position);

			FVector ballVel = direction * 600.0f;
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