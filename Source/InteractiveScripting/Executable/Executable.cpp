// Fill out your copyright notice in the Description page of Project Settings.
#include "Executable.h"

// Sets default values for this component's properties
AExecutable::AExecutable()
{
	//Set this actor to never tick to imrpove performance
	PrimaryActorTick.bCanEverTick = false;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
}

// Called when the game starts
void AExecutable::BeginPlay()
{
	Super::BeginPlay();
}

AExecutable::ExecuteResult AExecutable::Execute()
{
	//Ensure that next line isn't pointing to a piece of garbage data, which can happen if a connection is made and deleted
	if (!nextLine->IsValidLowLevel())
	{
		nextLine = nullptr;
	}

	if (nextLine == nullptr)
		return EndReached;	//There was no next line, return 0 to indicate succesful execution until the end was reached
	else
		return nextLine->Execute();
}

bool AExecutable::TestForLoop()
{
	//We've been here before, we are in a loop
	//Reset to be untested so we can test again on another connection later
	if (hasBeenTested)
	{
		hasBeenTested = false;
		return true;
	}

	//We reached the end, we aren't in a lopp
	if (!nextLine->IsValidLowLevel())
	{
		nextLine = nullptr;
		return false;
	}

	//Neither of the other checks returned a value, continue down the line
	hasBeenTested = true;
	bool finalResult = nextLine->TestForLoop();

	//We are returning back up the line, rest to be untested and return the final result
	hasBeenTested = false;
	return finalResult;

}

void AExecutable::SetAsExeValue(AConnectionManager* connectionManager)
{
	connectionManager->AssignExecutableValue(this);
}

void AExecutable::SetAsExeSlot(AConnectionManager* connectionManager)
{
	connectionManager->AssignExecutableSlot(&nextLine);
}