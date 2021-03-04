// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "Executable.h"
#include "Shoot.generated.h"

//Forward Declaration
class UVariableManager;
class ANumber;
class AVector2;

UCLASS()
class INTERACTIVESCRIPTING_API AShoot : public AExecutable
{
	GENERATED_BODY()
	
public:
	AShoot();

protected:
	UVariableManager* varManager;

	AVector2* vectorIn;
	ANumber* rotationIn;

	const float speed = 600.0f;
	const float maxTimer = 3.0f;

	const float spawnHeight = 70.0f;	//The height to spawn the ball at, set the to same as the player's height
	const float offsetDist = 100.0f;	//How far to move the ball before spawning it in, to prevent it spawning inside the player

	bool HasVarManager();
public:
	ExecuteResult Execute() override;

	UFUNCTION(BlueprintCallable)
		void SetVectorAsSlot(AConnectionManager* connectionmanager);

	UFUNCTION(BlueprintCallable)
		void SetRotationAsSlot(AConnectionManager* connectionManager);
};
