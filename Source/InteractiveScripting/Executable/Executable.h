// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Executable.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INTERACTIVESCRIPTING_API UExecutable : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UExecutable();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UExecutable* nextLine;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void Execute();

	UFUNCTION(BlueprintCallable)
		void SetNextLine(UExecutable* next);
		
};
