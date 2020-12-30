// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "Executable.h"
#include <InteractiveScripting/Evaluatable/Boolean.h>
#include "IfStatement.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class INTERACTIVESCRIPTING_API UIfStatement : public UExecutable
{
	GENERATED_BODY()
	
public:
	UIfStatement();

protected:
	UBoolean* condition;

	UExecutable* insideLine;

public:
	ExecuteResult Execute() override;

	UFUNCTION(BlueprintCallable)
		void SetCondition(UBoolean* cond);

	UFUNCTION(BlueprintCallable)
		void SetInsideLine(UExecutable* inLine);
};
