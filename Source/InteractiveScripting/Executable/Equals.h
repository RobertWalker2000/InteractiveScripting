// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include <InteractiveScripting/Executable/Executable.h>
#include <Interactivescripting/Evaluatable/NumVar.h>
#include "Equals.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class INTERACTIVESCRIPTING_API AEquals : public AExecutable
{
	GENERATED_BODY()
	
public:
	AEquals();

protected:
	ANumVar* leftSide;
	ANumber* rightSide;

public:

	UFUNCTION(BlueprintCallable)
		void SetLeftSideAsSlot(AConnectionManager* connectionManager);

	UFUNCTION(BlueprintCallable)
		void SetRightSideAsSlot(AConnectionManager* connectionManager);



	ExecuteResult Execute() override;
};
