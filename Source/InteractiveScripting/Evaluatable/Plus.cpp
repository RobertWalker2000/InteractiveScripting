// Fill out your copyright notice in the Description page of Project Settings.
#include "Plus.h"

APlus::APlus()
{

}

float APlus::Evaluate()
{
	if (!leftSide->IsValidLowLevel())
	{
		leftSide = nullptr;
	}

	if (!rightSide->IsValidLowLevel())
	{
		rightSide = nullptr;
	}

	if (leftSide == nullptr || rightSide == nullptr)
	{
		return NULL;
	}
	else
	{
		float value;
		value = leftSide->Evaluate() + rightSide->Evaluate();
		return value;
	}
}