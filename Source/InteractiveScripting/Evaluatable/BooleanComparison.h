// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "Boolean.h"
#include "BooleanComparison.generated.h"

UCLASS()
class INTERACTIVESCRIPTING_API ABooleanComparison : public ABoolean
{
	GENERATED_BODY()

protected:
	ABoolean* input1;
	ABoolean* input2;

public:
	UFUNCTION(BlueprintCallable)
		void SetInput1AsSlot(AConnectionManager* connectionManager);

	UFUNCTION(BlueprintCallable)
		void SetInput2AsSlot(AConnectionManager* connectionManager);
	
};
