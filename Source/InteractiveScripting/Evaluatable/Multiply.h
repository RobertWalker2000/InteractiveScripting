// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include <InteractiveScripting/Evaluatable/MathOperation.h>
#include "Multiply.generated.h"

UCLASS()
class INTERACTIVESCRIPTING_API AMultiply : public AMathOperation
{
	GENERATED_BODY()
	
public:
	AMultiply();

	float Evaluate() override;
};
