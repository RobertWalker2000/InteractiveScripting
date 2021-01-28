// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include <InteractiveScripting/Evaluatable/Number.h>
#include "Plus.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class INTERACTIVESCRIPTING_API APlus : public ANumber
{
	GENERATED_BODY()

public:
	APlus();

protected:
	ANumber* leftSide;
	ANumber* rightSide;

public:
	float Evaluate() override;

	UFUNCTION(BlueprintCallable)
		void SetLeft(ANumber* left);
	UFUNCTION(BlueprintCallable)
		void SetRight(ANumber* right);
};
