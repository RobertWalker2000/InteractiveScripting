// Fill out your copyright notice in the Description page of Project Settings.
#include "Plus.h"

APlus::APlus()
{
	isVariable = false;
}

void APlus::SetLeft(ANumber* left)
{
	leftSide = left;
}

void APlus::SetRight(ANumber* right)
{
	rightSide = right;
}

float APlus::Evaluate()
{
	//TODO: Ensure function adds left and right rather than a constant 10
	//This will require more variables to be in use first
	float value;
	value = leftSide->Evaluate() + 10.0f;
	return value;
}