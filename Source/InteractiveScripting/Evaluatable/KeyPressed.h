// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "Boolean.h"
#include "KeyPressed.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class INTERACTIVESCRIPTING_API UKeyPressed : public UBoolean
{
	GENERATED_BODY()
	
public:
	UKeyPressed();

protected:
	APlayerController* controller;
	FKey key;

	bool GetKey();
	bool GetController();
public:
	bool Evaluate() override;
};
