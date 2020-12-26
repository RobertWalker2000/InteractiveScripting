// Fill out your copyright notice in the Description page of Project Settings.
#include "ScriptCaller.h"

// Sets default values for this component's properties
UScriptCaller::UScriptCaller()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UScriptCaller::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void UScriptCaller::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	result = firstLine->Execute();

	if (result != UExecutable::ExecuteResult::EndReached)
	{
		//Handle Errors
	}
}

void UScriptCaller::SetFirstLine(UExecutable* first)
{
	firstLine = first;
}