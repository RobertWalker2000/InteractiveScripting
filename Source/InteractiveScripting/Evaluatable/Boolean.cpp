// Fill out your copyright notice in the Description page of Project Settings.
#include "Boolean.h"

ABoolean::ABoolean()
{
	dataType = DataType::BOOLEAN;
}

void ABoolean::SetAsBooleanValue(AConnectionManager* connectionManager)
{
	connectionManager->AssignBooleanVal(this);
}
