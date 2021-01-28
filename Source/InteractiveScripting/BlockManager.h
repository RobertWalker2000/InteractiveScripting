// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VariableManager.h"
#include "BlockManager.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INTERACTIVESCRIPTING_API ABlockManager : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ABlockManager();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UVariableManager* varManager;

public:	

	UFUNCTION(BlueprintCallable)
		void SetVarManager(UVariableManager* vm);

	UVariableManager* GetVarManager();
		
};
