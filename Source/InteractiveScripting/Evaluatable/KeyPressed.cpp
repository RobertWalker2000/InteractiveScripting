// Fill out your copyright notice in the Description page of Project Settings.
#include "KeyPressed.h"

AKeyPressed::AKeyPressed()
{
	
}

void AKeyPressed::SetKey(FString text)
{
	key = StringCast<ANSICHAR>(*text).Get();
}

bool AKeyPressed::Evaluate()
{
	if (HasController())	//Ensure we have a valid controller
	{
		if (key.IsValid())	//Ensure we have a valid key
		{
			return controller->IsInputKeyDown(key);
		}
	}

	//If we cant get the controller or the key is invalid, return false
	return false;
}

bool AKeyPressed::HasController()
{
	if (controller->IsValidLowLevel())
	{
		return true;
	}
	else
	{
		//Try and get the player controller
		controller = GetWorld()->GetFirstPlayerController();

		if (controller->IsValidLowLevel())
			return true;
	}

	return false;
}
