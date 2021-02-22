// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include <InteractiveScripting/Evaluatable/Number.h>
#include "MathOperation.generated.h"

UCLASS()
class INTERACTIVESCRIPTING_API AMathOperation : public ANumber
{
	GENERATED_BODY()
	
public:
	AMathOperation();

protected:
	ANumber* leftSide;
	ANumber* rightSide;

public:
	float Evaluate() override;

	UFUNCTION(BlueprintCallable)
		void SetLeftSideAsSlot(AConnectionManager* connectionManager);

	UFUNCTION(BlueprintCallable)
		void SetRightSideAsSlot(AConnectionManager* connectionManager);
};
