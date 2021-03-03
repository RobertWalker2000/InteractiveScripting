// Fill out your copyright notice in the Description page of Project Settings.
#include "VariableManager.h"

// Sets default values for this component's properties
UVariableManager::UVariableManager()
{
	//Need to tick so we can update delta time
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UVariableManager::BeginPlay()
{
	Super::BeginPlay();
	player = GetOwner();
}


// Called every frame
void UVariableManager::TickComponent(float dt, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(dt, TickType, ThisTickFunction);

	deltaTime = dt;
	shootTimer -= dt;
	FString string = "Delta Time: ";
	string.Append(FString::SanitizeFloat(dt));
	GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Red, string);
}

float UVariableManager::GetNumber(Variables varName)
{
	switch (varName)
	{
	case PositionX:
		return player->GetActorTransform().GetTranslation().X;
	case PositionY:
		return player->GetActorTransform().GetTranslation().Y;
	case Rotation:
		return player->GetActorTransform().GetRotation().Euler().Z;
	case ShootTimer:
		return shootTimer;
	case DeltaTime:
		return deltaTime;
	default:
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "Invalid variable name (Can't Get)");
		return NULL;
	}
}

void UVariableManager::SetNumber(Variables varName, float newVal)
{
	switch (varName)
	{
	case PositionX:
	{
		FTransform playerTrans = player->GetActorTransform();
		FVector playerPos = playerTrans.GetTranslation();
		playerPos.X = newVal;
		playerTrans.SetTranslation(playerPos);
		player->SetActorTransform(playerTrans);
		return;
	}
	case PositionY:
	{
		FTransform playerTrans = player->GetActorTransform();
		FVector playerPos = playerTrans.GetTranslation();
		playerPos.Y = newVal;
		playerTrans.SetTranslation(playerPos);
		player->SetActorTransform(playerTrans);
		return;
	}
	case Rotation:
	{
		FTransform playerTrans = player->GetActorTransform();
		FQuat playerRotation = playerTrans.GetRotation();
		FVector eulerRotation = playerRotation.Euler();
		eulerRotation = FVector(eulerRotation.X, eulerRotation.Y, newVal);
		playerRotation = FQuat::MakeFromEuler(eulerRotation);
		playerTrans.SetRotation(playerRotation);
		player->SetActorTransform(playerTrans);
		return;
	}
	case ShootTimer:
	{
		shootTimer = newVal;
		return;
	}
	default:
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "Invalid Variable name (Can't Set)");
		return;
	}
}

Variables UVariableManager::GetVarEnum(FString varName)
{
	if (varName == "PositionX")
		return PositionX;
	else if (varName == "PositionY")
		return PositionY;
	else if (varName == "Rotation")
		return Rotation;
	else
		return NoValue;
}
