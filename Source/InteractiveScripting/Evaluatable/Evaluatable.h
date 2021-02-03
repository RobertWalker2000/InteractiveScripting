// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <InteractiveScripting/ConnectionManager.h>
#include "Evaluatable.generated.h"

//Describes what kind of data the evaluatable returns
//Allows room for expansion to include new data types (e.g. string)
static enum DataType {NUMBER = 0, BOOLEAN= 1};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INTERACTIVESCRIPTING_API AEvaluatable : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	AEvaluatable();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	DataType dataType;
	bool isVariable;

public:	

	DataType GetDataType();
	bool IsVariable();
};
