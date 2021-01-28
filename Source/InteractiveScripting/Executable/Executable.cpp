// Fill out your copyright notice in the Description page of Project Settings.
#include "Executable.h"

// Sets default values for this component's properties
AExecutable::AExecutable()
{
	//Set this actor to never tick to imrpove performance
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts
void AExecutable::BeginPlay()
{
	Super::BeginPlay();
}

AExecutable::ExecuteResult AExecutable::Execute()
{
	if (nextLine == nullptr)
		return EndReached;	//There was no next line, return 0 to indicate succesful execution until the end was reached
	else
		return nextLine->Execute();
}

void AExecutable::SetNextLine(AExecutable* next)
{
	nextLine = next;
}