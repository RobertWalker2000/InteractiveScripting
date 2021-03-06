// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "VariableManager.generated.h"

static enum Variables {NoValue, PositionX, PositionY, Rotation, ShootTimer, DeltaTime};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INTERACTIVESCRIPTING_API UVariableManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UVariableManager();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	AActor* player;

	float deltaTime = 0.0f;
	float shootTimer = 0.0f;
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//Variable Managers
	//Some variables may be read only in the context of scripting, and so may only have a getter
	float GetNumber(Variables varName);
	void SetNumber(Variables varName, float newVal);

	static Variables GetVarEnum(FString varName);
};
