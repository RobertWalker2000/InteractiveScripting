#include "ConnectionManager.h"

// Sets default values
AConnectionManager::AConnectionManager()
{
	//Set this actor to never tick to imrpove performance
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AConnectionManager::BeginPlay()
{
	Super::BeginPlay();
	
}

void AConnectionManager::ClearValues()
{
	hasValue = false;

	exeValue = nullptr;
	
	numValue = nullptr;
	numVarValue = nullptr;

	boolValue = nullptr;
}

void AConnectionManager::ClearSlots()
{
	hasSlot = false;

	exeSlot = nullptr;

	numSlot = nullptr;
	numVarSlot = nullptr;

	boolSlot = nullptr;
}

void AConnectionManager::AssignExecutableValue(AExecutable* exeValueIn)
{
	ClearValues();
	exeValue = exeValueIn;
	hasValue = true;
	TryExecutableConnection();
}

void AConnectionManager::AssignExecutableSlot(AExecutable** exeSlotIn)
{
	ClearSlots();
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
			HandleImproperPair();
		}
		ClearValues();
		ClearSlots();
	}
}

void AConnectionManager::AssignNumVal(UNumber* numValueIn)
{
	ClearValues();
	numValue = numValueIn;
	hasValue = true;
	TryNumConnection();
}

void AConnectionManager::AssignNumVarVal(UNumVar* numVarValueIn)
{
	ClearValues();
	numVarValue = numVarValueIn;
	hasValue = true;
	TryNumConnection();
}

void AConnectionManager::AssignNumSlot(UNumber** numSlotIn)
{
	ClearSlots();
	numSlot = numSlotIn;
	hasSlot = true;
	TryNumConnection();
}

void AConnectionManager::AssignNumVarSlot(UNumVar** numVarSlotIn)
{
	ClearSlots();
	numVarSlot = numVarSlotIn;
	hasSlot = true;
	TryNumConnection();
}

void AConnectionManager::TryNumConnection()
{
	if (hasValue && hasSlot)
	{
		if (numSlot != nullptr && numValue != nullptr)
		{
			*numSlot = numValue;
		}
		else if (numVarValue != nullptr && numVarSlot != nullptr)
		{
			*numVarSlot = numVarValue;
		}
		else
		{
			//Invalid connection
			HandleImproperPair();
		}

		ClearValues();
		ClearSlots();
	}
}

void AConnectionManager::AssignBooleanVal(UBoolean* boolValueIn)
{
	ClearValues();
	boolValue = boolValueIn;
	hasValue = true;
	TryBoolConnection();
}

void AConnectionManager::AssignBooleanSlot(UBoolean** boolSlotIn)
{
	ClearSlots();
	boolSlot = boolSlotIn;
	hasSlot = true;
	TryBoolConnection();
}

void AConnectionManager::TryBoolConnection()
{
	if (hasValue && hasSlot)
	{
		if (boolValue != nullptr && boolSlot != nullptr)
		{

		}
		else
		{
			//Invalid pairing
			HandleImproperPair();
		}

		ClearValues();
		ClearSlots();
	}
}

void AConnectionManager::HandleImproperPair()
{
	//TODO - Implement function
}