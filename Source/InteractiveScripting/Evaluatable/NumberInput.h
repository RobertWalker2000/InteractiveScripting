// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "Number.h"
#include "NumberInput.generated.h"

UCLASS()
class INTERACTIVESCRIPTING_API ANumberInput : public ANumber
{
	GENERATED_BODY()
	
protected:
	float value = NULL;

public:
	float Evaluate() override;

	UFUNCTION(BlueprintCallable)
		void SetValue(float input);
};
