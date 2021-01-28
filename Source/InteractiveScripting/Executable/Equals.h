// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include <InteractiveScripting/Executable/Executable.h>
#include <Interactivescripting/Evaluatable/NumVar.h>
#include "Equals.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class INTERACTIVESCRIPTING_API AEquals : public AExecutable
{
	GENERATED_BODY()
	
public:
	AEquals();

protected:
	AEvaluatable* leftSide;
	AEvaluatable* rightSide;
public:
	UFUNCTION(BlueprintCallable)
		void SetLeft(AEvaluatable* left);
	UFUNCTION(BlueprintCallable)
		void SetRight(AEvaluatable* right);

	ExecuteResult Execute() override;
};
