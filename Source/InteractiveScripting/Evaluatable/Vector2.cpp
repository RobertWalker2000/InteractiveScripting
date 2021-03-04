// Fill out your copyright notice in the Description page of Project Settings.
#include "Vector2.h"

AVector2::AVector2()
{

}

void AVector2::SetAsVectorValue(AConnectionManager* connectionManager)
{
	connectionManager->AssignVectorVal(this);
}
