// Fill out your copyright notice in the Description page of Project Settings.
#include "Evaluatable.h"

// Sets default values for this component's properties
AEvaluatable::AEvaluatable()
{
	//Set this actor to never tick to imrpove performance
	PrimaryActorTick.bCanEverTick = false;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
}

// Called when the game starts
void AEvaluatable::BeginPlay()
{
	Super::BeginPlay();
}
