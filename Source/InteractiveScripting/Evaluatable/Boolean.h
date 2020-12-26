// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "Evaluatable.h"
#include "Boolean.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class INTERACTIVESCRIPTING_API UBoolean : public UEvaluatable
{
	GENERATED_BODY()
	
public:
	UBoolean();

	virtual bool Evaluate() { return NULL; };
};
