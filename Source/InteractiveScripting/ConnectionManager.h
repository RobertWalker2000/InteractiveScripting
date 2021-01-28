#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Executable/Executable.h"
#include "Evaluatable/NumVar.h"
#include "Evaluatable/Boolean.h"
#include "ConnectionManager.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class INTERACTIVESCRIPTING_API AConnectionManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AConnectionManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Track if we have a slot/value assigned to catch improper pairings
	bool hasValue = false;
	bool hasSlot = false;

	void HandleImproperPair();

	//Input Values
	AExecutable* exeValue;

	UNumber* numValue;
	UNumVar* numVarValue;

	UBoolean* boolValue;

	//Input Slots
	AExecutable** exeSlot;

	UNumber** numSlot;
	UNumVar** numVarSlot;

	UBoolean** boolSlot;

public:	

	//Reference clearers
	void ClearValues();
	void ClearSlots();

	//Executable connections
	void AssignExecutableValue(AExecutable* exeVal);
	void AssignExecutableSlot(AExecutable** exeSlotIn);

	void TryExecutableConnection();

	//Number connections
	void AssignNumVal(UNumber* numValueIn);
	void AssignNumVarVal(UNumVar* numVarValIn);

	void AssignNumSlot(UNumber** numSlotIn);
	void AssignNumVarSlot(UNumVar** numVarSlotIn);

	void TryNumConnection();

	//Boolean connections
	void AssignBooleanVal(UBoolean* boolValueIn);
	void AssignBooleanSlot(UBoolean** boolSlotIn);

	void TryBoolConnection();

};
