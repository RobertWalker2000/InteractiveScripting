// Fill out your copyright notice in the Description page of Project Settings.
#include "VariableManager.h"

// Sets default values for this component's properties
UVariableManager::UVariableManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UVariableManager::BeginPlay()
{
	Super::BeginPlay();
	player = GetOwner();
}


// Called every frame
void UVariableManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

float UVariableManager::GetNumber(Variables varName)
{
	switch (varName)
	{
	case PositionX:
		return player->GetActorTransform().GetTranslation().X;
	case PositionY:
		return player->GetActorTransform().GetTranslation().Y;
	default:
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "NumVar has no assigned variable");
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
	default:
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "NumVar has no assigned variable");
		return;
	}
}

Variables UVariableManager::GetVarEnum(FString varName)
{
	if (varName == "PositionX")
		return PositionX;
	else if (varName == "PositionY")
		return PositionY;
	else
		return NoValue;
}
