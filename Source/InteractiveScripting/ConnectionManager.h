#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Components/Button.h>
#include "ConnectionManager.generated.h"

//Forward Declarations
class AExecutable;
class ANumber;
class ANumVar;
class ABoolean;

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
	bool areButtonsValid = true;

	void HandleImproperPair();

	//Input Values
	AExecutable* exeValue;

	ANumber* numValue;
	ANumVar* numVarValue;

	ABoolean* boolValue;

	//Input Slots
	AExecutable** exeSlot;

	ANumber** numSlot;
	ANumVar** numVarSlot;

	ABoolean** boolSlot;

	UButton* slotButton;
	UButton* valueButton;

public:	
	//Needs to tick in order to validate buttons for visual connections
	virtual void Tick(float dt) override;

	//Reference clearers
	void ClearValues();
	void ClearSlots();

	//Executable connections
	void AssignExecutableValue(AExecutable* exeVal);

	void AssignExecutableSlot(AExecutable** exeSlotIn);

	void TryExecutableConnection();

	//Number connections
	void AssignNumVal(ANumber* numValueIn);

	void AssignNumVarVal(ANumber* numValIn, ANumVar* numVarValIn);

	void AssignNumSlot(ANumber** numSlotIn);

	void AssignNumVarSlot(ANumVar** numVarSlotIn);

	void TryNumConnection();

	//Boolean connections
	void AssignBooleanVal(ABoolean* boolValueIn);

	void AssignBooleanSlot(ABoolean** boolSlotIn);

	void TryBoolConnection();

	//Visual Linking Functions
	UFUNCTION(BlueprintCallable)
		void AssignSlotButton(UButton* button);

	UFUNCTION(BlueprintCallable)
		void AssignValueButton(UButton* button);

	UFUNCTION(BlueprintCallable)
		bool IsSlotButton(UButton* button);

	UFUNCTION(BlueprintCallable)
		UButton* GetValueButton(UButton* button);

	UFUNCTION(BlueprintCallable)
		UButton* GetActiveButton();

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		bool ShouldDrawLines = true;

};
