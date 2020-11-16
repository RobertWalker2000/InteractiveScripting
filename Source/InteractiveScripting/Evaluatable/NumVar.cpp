// Fill out your copyright notice in the Description page of Project Settings.
#include "NumVar.h"
#include <Kismet/GameplayStatics.h>

UNumVar::UNumVar()
{
	isVariable = true;
	FName name = "Player";
	TArray<AActor*> actors;
	UGameplayStatics::GetAllActorsWithTag(this, name, actors);
}

float UNumVar::Evaluate()
{
	return 0;
}
