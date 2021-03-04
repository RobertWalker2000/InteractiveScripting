// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "Vector2.h"
#include "CreateVector.generated.h"

//Forward Declaration
class ANumber;

UCLASS()
class INTERACTIVESCRIPTING_API ACreateVector : public AVector2
{
	GENERATED_BODY()
	
public:
	ACreateVector();

protected:
	ANumber* numX;
	ANumber* numY;

public:

	FMyVector Evaluate() override;

	UFUNCTION(BlueprintCallable)
		void SetNumXAsSlot(AConnectionManager* connectionManager);

	UFUNCTION(BlueprintCallable)
		void SetNumYAsSlot(AConnectionManager* connectionManager);
};
