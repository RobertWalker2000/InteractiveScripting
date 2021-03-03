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

	if (HasVarManager())
	{
		positionX = varManager->GetNumber(Variables::PositionX);
		positionY = varManager->GetNumber(Variables::PositionY);
		rotation = varManager->GetNumber(Variables::Rotation);
		speed = 60.0f;
	}

	FTransform spawnTransform = FTransform::Identity;

	FVector position = FVector(positionX, positionY, 70.0f);

	//Create a vector representing the forward vector of the player based on the inputs
	FVector direction = FVector::RightVector;
	direction = direction.RotateAngleAxis(rotation, FVector::UpVector);
	direction.Normalize();

	//Move the spawn position along the forward vector a small amount to ensure it is outside the player
	position += (direction * 60.0f);
	spawnTransform.SetTranslation(position);

	FVector ballVel = direction * 60.0f;
	AProjectile* projectile = GetWorld()->SpawnActor<AProjectile>(AProjectile::StaticClass(), spawnTransform);
	projectile->ballMesh->AddImpulse(ballVel, FName(), true);

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