// Fill out your copyright notice in the Description page of Project Settings.
#include "Number.h"

ANumber::ANumber()
{
	dataType = DataType::NUMBER;
}

void ANumber::SetAsNumValue(AConnectionManager* connectionManager)
{
	connectionManager->AssignNumVal(this);
}