// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include <InteractiveScripting/Evaluatable/Number.h>
#include "Plus.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class INTERACTIVESCRIPTING_API UPlus : public UNumber
{
	GENERATED_BODY()

public:
	UPlus();

protected:
	UNumber* leftSide;
	UNumber* rightSide;

public:
	float Evaluate() override;

	UFUNCTION(BlueprintCallable)
		void SetLeft(UNumber* left);
	UFUNCTION(BlueprintCallable)
		void SetRight(UNumber* right);
};
