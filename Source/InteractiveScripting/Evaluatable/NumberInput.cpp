// Fill out your copyright notice in the Description page of Project Settings.
#include "NumberInput.h"

void ANumberInput::SetValue(float input)
{
	value = input;
}

float ANumberInput::Evaluate()
{
	return value;
}