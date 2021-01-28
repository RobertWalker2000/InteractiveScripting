// Fill out your copyright notice in the Description page of Project Settings.
#include "BlockManager.h"
#include <Kismet/GameplayStatics.h>

// Sets default values for this component's properties
ABlockManager::ABlockManager()
{
	//Set this actor to never tick to imrpove performance
	PrimaryActorTick.bCanEverTick = false;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
}

// Called when the game starts
void ABlockManager::BeginPlay()
{
	Super::BeginPlay();
}

void ABlockManager::SetVarManager(UVariableManager* vm)
{
	varManager = vm;
}

UVariableManager* ABlockManager::GetVarManager()
{
	return varManager;
}