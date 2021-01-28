// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <InteractiveScripting/Executable/Executable.h>
#include "ScriptCaller.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INTERACTIVESCRIPTING_API UScriptCaller : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UScriptCaller();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	AExecutable* firstLine;
	AExecutable::ExecuteResult result;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
		void SetFirstLine(AExecutable* first);

};
