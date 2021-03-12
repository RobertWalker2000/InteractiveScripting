// Fill out your copyright notice in the Description page of Project Settings.


#include "OutOfBounds.h"

// Sets default values
AOutOfBounds::AOutOfBounds()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent->SetMobility(EComponentMobility::Static);

	//Create the mesh component and attach it to the root
	wallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball Mesh"));
	wallMesh->AttachTo(RootComponent);

	//Attcach the sphere mesh to the ballMesh component
	static ConstructorHelpers::FObjectFinder<UStaticMesh> sphereAsset(TEXT("/ENGINE/BasicShapes/Cube"));
	wallMesh->SetStaticMesh(sphereAsset.Object);
	wallMesh->SetRelativeScale3D(FVector(1.0f));

	static ConstructorHelpers::FObjectFinder<UMaterial> materialAsset(TEXT("Material'/Game/OutOfBounds.OutOfBounds'"));
	wallMaterial = materialAsset.Object;
	dynamicMaterial = UMaterialInstanceDynamic::Create(wallMaterial, wallMesh);
	wallMesh->SetMaterial(0, dynamicMaterial);

	//Allow the prohectile to be moved but ignore gravity
	wallMesh->SetMobility(EComponentMobility::Static);
	wallMesh->SetSimulatePhysics(false);
	wallMesh->SetGenerateOverlapEvents(true);

	//Ensure the rigidbody creates collision events when it hits something
	wallMesh->SetNotifyRigidBodyCollision(false);
	SetActorEnableCollision(true);

}

// Called when the game starts or when spawned
void AOutOfBounds::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOutOfBounds::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AOutOfBounds::NotifyActorBeginOverlap(AActor* Other)
{
	if (Other->ActorHasTag("Player"))
	{
		GEngine->AddOnScreenDebugMessage(-5, 5.0f, FColor::Red, "Overlap Detected");
	}
}