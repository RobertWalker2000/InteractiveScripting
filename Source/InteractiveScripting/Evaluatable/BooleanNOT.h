// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "Boolean.h"
#include "BooleanNOT.generated.h"

UCLASS()
class INTERACTIVESCRIPTING_API ABooleanNOT : public ABoolean
{
	GENERATED_BODY()
	
protected:
	ABoolean* input;

public:
	bool Evaluate() override;

	UFUNCTION(BlueprintCallable)
		void SetInputAsSlot(AConnectionManager* connectionManager);
};
