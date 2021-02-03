// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "Evaluatable.h"
#include "Number.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class INTERACTIVESCRIPTING_API ANumber : public AEvaluatable
{
	GENERATED_BODY()

public:
	ANumber();

protected:


public:
	virtual float Evaluate() { return NULL; };
	
	UFUNCTION(BlueprintCallable)
		void SetAsNumValue(AConnectionManager* connectionManager);
};
