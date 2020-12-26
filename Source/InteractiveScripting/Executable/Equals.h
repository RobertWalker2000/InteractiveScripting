// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include <InteractiveScripting/Executable/Executable.h>
#include <Interactivescripting/Evaluatable/NumVar.h>
#include "Equals.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class INTERACTIVESCRIPTING_API UEquals : public UExecutable
{
	GENERATED_BODY()
	
public:
	UEquals();

protected:
	UEvaluatable* leftSide;
	UEvaluatable* rightSide;
public:
	UFUNCTION(BlueprintCallable)
		void SetLeft(UEvaluatable* left);
	UFUNCTION(BlueprintCallable)
		void SetRight(UEvaluatable* right);

	ExecuteResult Execute() override;
};
