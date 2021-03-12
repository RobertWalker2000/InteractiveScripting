#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OutOfBounds.generated.h"

UCLASS()
class INTERACTIVESCRIPTING_API AOutOfBounds : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOutOfBounds();
	UStaticMeshComponent* wallMesh;

	UMaterial* wallMaterial;
	UMaterialInstanceDynamic* dynamicMaterial;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void NotifyActorBeginOverlap(AActor* Other) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
