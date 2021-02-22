// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include <InteractiveScripting/Evaluatable/MathOperation.h>
#include "Divide.generated.h"

UCLASS()
class INTERACTIVESCRIPTING_API ADivide : public AMathOperation
{
	GENERATED_BODY()
	
public:
	ADivide();

	float Evaluate() override;
};
