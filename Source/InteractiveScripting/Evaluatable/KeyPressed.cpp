// Fill out your copyright notice in the Description page of Project Settings.
#include "KeyPressed.h"

AKeyPressed::AKeyPressed()
{

}

bool AKeyPressed::GetController()
{
	//Dont need to find the controller if we already have it
	if (controller)
		return true;

	//Try and get the player controller
	controller = GetWorld()->GetFirstPlayerController();

	//Return whether or not we managed to get the controller
	if (controller)
		return true;
	else
		return false;
}

bool AKeyPressed::GetKey()
{
	//Get the relavent key from the component name
	FString keyString = this->GetName();

	//Set the key using the string, which must be cast to the appropriate type
	key = StringCast<ANSICHAR>(*keyString).Get();
	return key.IsValid();
}

bool AKeyPressed::Evaluate()
{
	if (GetController())	//Ensure we have a valid controller
	{
		if (GetKey())	//Ensure we have a valid key
		{
			return controller->IsInputKeyDown(key);
		}
	}

	//If we cant get the controller or the key is invalid, return false
	return false;
}
