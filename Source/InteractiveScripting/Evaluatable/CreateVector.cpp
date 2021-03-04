// Fill out your copyright notice in the Description page of Project Settings.
#include "CreateVector.h"
#include "Number.h"

ACreateVector::ACreateVector()
{

}

void ACreateVector::SetNumXAsSlot(AConnectionManager* connectionManager)
{
	connectionManager->AssignNumSlot(&numX);
}

void ACreateVector::SetNumYAsSlot(AConnectionManager* connectionManager)
{
	connectionManager->AssignNumSlot(&numY);
}

FMyVector ACreateVector::Evaluate()
{
	FMyVector result;

	if (!numX->IsValidLowLevel())
	{
		numX = nullptr;
	}

	if (!numY->IsValidLowLevel())
	{
		numY = nullptr;
	}

	if (numX == nullptr || numY == nullptr)
	{
		result.x = 0.0f;
		result.y = 0.0f;
	}
	else
	{
		result.x = numX->Evaluate();
		result.y = numY->Evaluate();
	}

	return result;
}
