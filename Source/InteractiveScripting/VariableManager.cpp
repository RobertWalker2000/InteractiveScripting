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
	
	SetPositionX(GetPositionX() + 1);
}

float UVariableManager::GetPositionX()
{
	return player->GetActorTransform().GetTranslation().X;
}

void UVariableManager::SetPositionX(float newPosX)
{
	FTransform playerTrans = player->GetActorTransform();
	FVector playerPos = playerTrans.GetTranslation();
	playerPos.X = newPosX;
	playerTrans.SetTranslation(playerPos);
	player->SetActorTransform(playerTrans);
}

float UVariableManager::GetPositionY()
{
	return player->GetActorTransform().GetTranslation().Y;
}

void UVariableManager::SetPositionY(float newPosY)
{
	FTransform playerTrans = player->GetActorTransform();
	FVector playerPos = playerTrans.GetTranslation();
	playerPos.Y = newPosY;
	playerTrans.SetTranslation(playerPos);
	player->SetActorTransform(playerTrans);
}


