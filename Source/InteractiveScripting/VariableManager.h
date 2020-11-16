// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "VariableManager.generated.h"

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
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//Variable Managers
	//Some variables may be read only in the context of scripting, and so may only have a getter
	float GetPositionX();
	void SetPositionX(float newXPos);

	float GetPositionY();
	void SetPositionY(float newYPos);

		
};
