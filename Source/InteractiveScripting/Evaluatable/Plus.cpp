// Fill out your copyright notice in the Description page of Project Settings.
#include "Plus.h"

UPlus::UPlus()
{
	isVariable = false;
}

void UPlus::SetLeft(UNumber* left)
{
	leftSide = left;
}

void UPlus::SetRight(UNumber* right)
{
	rightSide = right;
}

float UPlus::Evaluate()
{
	//TODO: Ensure function adds left and right rather than a constant 10
	//This will require more variables to be in use first
	float value;
	value = leftSide->Evaluate() + 10.0f;
	return value;
}