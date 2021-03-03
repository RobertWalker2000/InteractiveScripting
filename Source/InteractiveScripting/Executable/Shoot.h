// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "Executable.h"
#include "InteractiveScripting/VariableManager.h"
#include "InteractiveScripting/Projectile.h"
#include "Shoot.generated.h"

UCLASS()
class INTERACTIVESCRIPTING_API AShoot : public AExecutable
{
	GENERATED_BODY()
	
public:
	AShoot();

protected:
	UVariableManager* varManager;

	float positionX = 0, positionY = 0, rotation = 0, speed = 0;

	bool HasVarManager();
public:
	ExecuteResult Execute() override;
};
