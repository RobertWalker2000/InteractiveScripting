#include "ConnectionManager.h"

// Sets default values
AConnectionManager::AConnectionManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AConnectionManager::BeginPlay()
{
	Super::BeginPlay();
	
}

void AConnectionManager::AssignExecutableValue(UExecutable* exeValueIn)
{
	//ClearValues();	TODO - Implement function
	exeValue = exeValueIn;
	hasValue = true;
	TryExecutableConnection();
}

void AConnectionManager::AssignExecutableSlot(UExecutable** exeSlotIn)
{
	//ClearSlots();		TODO - Implement function
	exeSlot = exeSlotIn;
	hasSlot = true;
	TryExecutableConnection();
}

void AConnectionManager::TryExecutableConnection()
{
	if (hasValue && hasSlot)
	{
		//If we have a compatible slot and value, connect the 2
		if ((exeSlot != nullptr) && (exeValue != nullptr))
		{
			*exeSlot = exeValue;
		}
		else
		{
			//If we reach here we have an improper pairing. This should be expressed to the player
			//HandleImproperPair();		TODO - Implement function
		}
		//ClearValues();	TODO - Implement function
		//ClearSlots();		TODO - Implement function
	}
}