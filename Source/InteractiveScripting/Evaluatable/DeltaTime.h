// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "Number.h"
#include <InteractiveScripting/VariableManager.h>
#include "DeltaTime.generated.h"

UCLASS()
class INTERACTIVESCRIPTING_API ADeltaTime : public ANumber
{
	GENERATED_BODY()


protected:
	UVariableManager* varManager;

	bool HasVarManager();

public:

	float Evaluate() override;
};
