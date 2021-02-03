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
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "Executable Connection Made");
			*exeSlot = exeValue;
		}
		else
		{
			//If we reach here we have an improper pairing. This should be expressed to the player
			HandleImproperPair();
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "Executable Connection Failed");

		}
		ClearValues();
		ClearSlots();

	}
}

void AConnectionManager::AssignNumVal(ANumber* numValueIn)
{
	ClearValues();
	numValue = numValueIn;
	hasValue = true;
	TryNumConnection();
}

void AConnectionManager::AssignNumVarVal(ANumber* numValIn, ANumVar* numVarValueIn)
{
	ClearValues();
	numValue = numValIn;
	numVarValue = numVarValueIn;
	hasValue = true;
	TryNumConnection();
}

void AConnectionManager::AssignNumSlot(ANumber** numSlotIn)
{
	ClearSlots();
	numSlot = numSlotIn;
	hasSlot = true;
	TryNumConnection();
}

void AConnectionManager::AssignNumVarSlot(ANumVar** numVarSlotIn)
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
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "Number Connection Made");
			*numSlot = numValue;
		}
		else if (numVarValue != nullptr && numVarSlot != nullptr)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "NumVar Connection Made");
			*numVarSlot = numVarValue;
		}
		else
		{
			//Invalid connection
			HandleImproperPair();
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "Number Connection Failed");
		}

		ClearValues();
		ClearSlots();
	}
}

void AConnectionManager::AssignBooleanVal(ABoolean* boolValueIn)
{
	ClearValues();
	boolValue = boolValueIn;
	hasValue = true;
	TryBoolConnection();
}

void AConnectionManager::AssignBooleanSlot(ABoolean** boolSlotIn)
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
			*boolSlot = boolValue;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "Boolean Connection Made");
		}
		else
		{
			//Invalid pairing
			HandleImproperPair();
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "Boolean Connection Failed");
		}

		ClearValues();
		ClearSlots();
	}
}

void AConnectionManager::HandleImproperPair()
{
	//TODO - Implement function
}