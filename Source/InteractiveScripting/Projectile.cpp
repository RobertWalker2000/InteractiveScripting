// Fill out your copyright notice in the Description page of Project Settings.
#include "Projectile.h"

// Sets default values
AProjectile::AProjectile()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent->SetMobility(EComponentMobility::Movable);

	//Create the mesh component and attach it to the root
	ballMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball Mesh"));
	ballMesh->AttachTo(RootComponent);

	//Attcach the sphere mesh to the ballMesh component
	static ConstructorHelpers::FObjectFinder<UStaticMesh> sphereAsset(TEXT("/ENGINE/BasicShapes/Sphere"));
	ballMesh->SetStaticMesh(sphereAsset.Object);
	ballMesh->SetRelativeScale3D(FVector(0.5f));

	//Allow the prohectile to be moved but ignore gravity
	ballMesh->SetMobility(EComponentMobility::Movable);
	ballMesh->SetSimulatePhysics(true);
	ballMesh->SetEnableGravity(false);

	//Continuous collision detection to ensure the ball doesn't clip through other objects and ignore collisions
	ballMesh->SetUseCCD(true);

	//Ensure the rigidbody creates collision events when it hits something
	ballMesh->SetNotifyRigidBodyCollision(true);
	SetActorEnableCollision(true);
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
	//Set the projectile to self destruct if it doesn't hit anything within a timeframe
	SetLifeSpan(10.0f);
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AProjectile::NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

	//Check what we hit, if it was a target then flag the target as hit
	//After resolving the hit, delete the projectile
	Destroy();
}
