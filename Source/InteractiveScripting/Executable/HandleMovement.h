// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "Executable.h"
#include "InteractiveScripting/Evaluatable/Number.h"
#include "InteractiveScripting/BlockManager.h"
#include "InteractiveScripting/VariableManager.h"
#include "HandleMovement.generated.h"

UCLASS()
class INTERACTIVESCRIPTING_API AHandleMovement : public AExecutable
{
	GENERATED_BODY()
	
public:

	AHandleMovement();

protected:
	bool HasPlayerController();
	bool HasVarManager();
	void DoMovementControls();

	APlayerController* controller;
	UVariableManager* varManager;
	FKey up, down, left, right;

	ANumber* moveSpeed;
	ANumber* deltaTime;

public:

	ExecuteResult Execute() override;

	UFUNCTION(BlueprintCallable)
		void SetMoveSpeedAsSlot(AConnectionManager* connectionManager);

	UFUNCTION(BlueprintCallable)
		void SetDeltaTimeAsSlot(AConnectionManager* connectionManager);
};
