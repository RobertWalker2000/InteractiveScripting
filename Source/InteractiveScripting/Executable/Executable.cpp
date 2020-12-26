// Fill out your copyright notice in the Description page of Project Settings.
#include "Executable.h"

// Sets default values for this component's properties
UExecutable::UExecutable()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}

// Called when the game starts
void UExecutable::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void UExecutable::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

UExecutable::ExecuteResult UExecutable::Execute()
{
	if (nextLine == nullptr)
		return EndReached;	//There was no next line, return 0 to indicate succesful execution until the end was reached
	else
		return nextLine->Execute();
}

void UExecutable::SetNextLine(UExecutable* next)
{
	nextLine = next;
}