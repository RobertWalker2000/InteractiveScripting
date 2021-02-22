// Fill out your copyright notice in the Description page of Project Settings.
#include "MathOperation.h"

AMathOperation::AMathOperation()
{

}

void AMathOperation::SetLeftSideAsSlot(AConnectionManager* connectionManager)
{
	connectionManager->AssignNumSlot(&leftSide);
}

void AMathOperation::SetRightSideAsSlot(AConnectionManager* connectionManager)
{
	connectionManager->AssignNumSlot(&rightSide);
}

float AMathOperation::Evaluate()
{
	return NULL;
}