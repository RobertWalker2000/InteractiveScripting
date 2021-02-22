// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include <InteractiveScripting/Evaluatable/MathOperation.h>
#include "Subtract.generated.h"

UCLASS()
class INTERACTIVESCRIPTING_API ASubtract : public AMathOperation
{
	GENERATED_BODY()
	
public:
	ASubtract();

	float Evaluate() override;

};
