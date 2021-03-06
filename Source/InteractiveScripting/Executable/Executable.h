// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <InteractiveScripting/ConnectionManager.h>
#include "Executable.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INTERACTIVESCRIPTING_API AExecutable : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	AExecutable();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	AExecutable* nextLine;

	bool hasBeenTested = false;
public:	
	static enum ExecuteResult
	{
		EndReached,
		MissingComponent,
		IncompatibleComponent
	};

	virtual ExecuteResult Execute();

	virtual bool TestForLoop();
		
	UFUNCTION(BlueprintCallable)
		void SetAsExeValue(AConnectionManager* connectionManager);

	UFUNCTION(BlueprintCallable)
		void SetAsExeSlot(AConnectionManager* connectionManager);
};
