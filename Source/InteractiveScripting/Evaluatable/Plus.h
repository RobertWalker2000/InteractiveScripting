// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include <InteractiveScripting/Evaluatable/MathOperation.h>
#include "Plus.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class INTERACTIVESCRIPTING_API APlus : public AMathOperation
{
	GENERATED_BODY()

public:
	APlus();

	float Evaluate() override;

};
