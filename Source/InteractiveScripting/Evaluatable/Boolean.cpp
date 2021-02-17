// Fill out your copyright notice in the Description page of Project Settings.
#include "Boolean.h"

ABoolean::ABoolean()
{

}

void ABoolean::SetAsBooleanValue(AConnectionManager* connectionManager)
{
	connectionManager->AssignBooleanVal(this);
}
