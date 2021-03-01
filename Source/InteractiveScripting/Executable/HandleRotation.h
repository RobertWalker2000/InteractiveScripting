// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "Executable.h"
#include "InteractiveScripting/Evaluatable/Number.h"
#include "InteractiveScripting/BlockManager.h"
#include "InteractiveScripting/VariableManager.h"
#include "HandleRotation.generated.h"

UCLASS()
class INTERACTIVESCRIPTING_API AHandleRotation : public AExecutable
{
	GENERATED_BODY()
	
public:
	AHandleRotation();

protected:

	bool HasPlayerController();
	bool HasVarManager();
	void DoRotationControls();

	APlayerController* controller;
	UVariableManager* varManager;
	FKey rotLeft, rotRight;

	ANumber* rotationSpeed;
	ANumber* deltaTime;

public:

	ExecuteResult Execute() override;

	UFUNCTION(BlueprintCallable)
		void SetRotationSpeedAsSlot(AConnectionManager* connectionManager);

	UFUNCTION(BlueprintCallable)
		void SetDeltaTimeAsSlot(AConnectionManager* connectionManager);
};
