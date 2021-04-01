// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

class USoundCue;
class UAudioComponent;

UCLASS()
class INTERACTIVESCRIPTING_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();
	UStaticMeshComponent* ballMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Used to play audio cue when projectile is spawned
	USoundCue* soundCue;
	UAudioComponent* audioComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
