// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "Number.h"
#include <InteractiveScripting/VariableManager.h>
#include "NumVar.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class INTERACTIVESCRIPTING_API UNumVar : public UNumber
{
	GENERATED_BODY()

public:
	UNumVar();

protected:
	UVariableManager* varManager;

public:
	float Evaluate() override;
};
