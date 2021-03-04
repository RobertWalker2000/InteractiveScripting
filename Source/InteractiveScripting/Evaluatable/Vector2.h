// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "Evaluatable.h"
#include "InteractiveScripting/ConnectionManager.h"
#include "Vector2.generated.h"

USTRUCT()
struct INTERACTIVESCRIPTING_API FMyVector
{
	GENERATED_USTRUCT_BODY()

public:
	float x = 0.0f;
	float y = 0.0f;
};

UCLASS()
class INTERACTIVESCRIPTING_API AVector2 : public AEvaluatable
{
	GENERATED_BODY()

public:
	AVector2();

protected:

public:

	virtual FMyVector Evaluate() { return FMyVector(); }

	UFUNCTION(BlueprintCallable)
		void SetAsVectorValue(AConnectionManager* connectionManager);
	
};
