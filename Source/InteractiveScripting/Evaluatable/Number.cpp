// Fill out your copyright notice in the Description page of Project Settings.
#include "Number.h"

ANumber::ANumber()
{

}

void ANumber::SetAsNumValue(AConnectionManager* connectionManager)
{
	connectionManager->AssignNumVal(this);
}