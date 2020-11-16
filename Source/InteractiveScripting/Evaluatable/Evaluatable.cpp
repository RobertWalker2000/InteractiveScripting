// Fill out your copyright notice in the Description page of Project Settings.
#include "Evaluatable.h"

// Sets default values for this component's properties
UEvaluatable::UEvaluatable()
{
	//Doesn't need to tick
	PrimaryComponentTick.bCanEverTick = false;
}

// Called when the game starts
void UEvaluatable::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void UEvaluatable::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

DataType UEvaluatable::GetDataType()
{
	return dataType;
}

bool UEvaluatable::IsVariable()
{
	return isVariable;
}