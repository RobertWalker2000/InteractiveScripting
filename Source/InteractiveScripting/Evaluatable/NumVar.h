// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "Number.h"
#include <InteractiveScripting/VariableManager.h>
#include <InteractiveScripting/BlockManager.h>
#include "NumVar.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class INTERACTIVESCRIPTING_API ANumVar : public ANumber
{
	GENERATED_BODY()

public:
	ANumVar();

protected:
	UVariableManager* varManager;
	ABlockManager* blockManager;
	bool HasVarType();
	Variables varName;

public:
	float Evaluate() override;
	void SetValue(float val);
};
