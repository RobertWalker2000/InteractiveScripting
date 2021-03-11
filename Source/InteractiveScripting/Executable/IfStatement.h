// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "Executable.h"
#include <InteractiveScripting/Evaluatable/Boolean.h>
#include "IfStatement.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class INTERACTIVESCRIPTING_API AIfStatement : public AExecutable
{
	GENERATED_BODY()
	
public:
	AIfStatement();

protected:
	ABoolean* condition;

	AExecutable* insideLine;

public:
	ExecuteResult Execute() override;

	bool TestForLoop() override;

	UFUNCTION(BlueprintCallable)
		void SetConditionAsSlot(AConnectionManager* connectionManager);

	UFUNCTION(BlueprintCallable)
		void SetInsideLineAsSLot(AConnectionManager* connectionManager);
};
