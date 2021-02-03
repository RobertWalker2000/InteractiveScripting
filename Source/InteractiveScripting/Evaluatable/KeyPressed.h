// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "Boolean.h"
#include "KeyPressed.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class INTERACTIVESCRIPTING_API AKeyPressed : public ABoolean
{
	GENERATED_BODY()
	
public:
	AKeyPressed();

protected:
	APlayerController* controller;
	FKey key;

	//Should be removable after UI linking
	bool GetKey();

	bool GetController();
public:
	bool Evaluate() override;

	UFUNCTION(BlueprintCallable)
		void SetKey(FString textIn);
};
