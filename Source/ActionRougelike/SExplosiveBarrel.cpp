// Fill out your copyright notice in the Description page of Project Settings.


#include "SExplosiveBarrel.h"




// Sets default values
ASExplosiveBarrel::ASExplosiveBarrel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMeshComp=CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	
	StaticMeshComp->OnComponentHit.AddDynamic(this,&ASExplosiveBarrel::Boom);

	
	
}

// Called when the game starts or when spawned
void ASExplosiveBarrel::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASExplosiveBarrel::Boom(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	FTransform SpawnTm=FTransform(GetActorRotation(),GetActorLocation());

	FActorSpawnParameters SpawnParams;
	
	SpawnParams.SpawnCollisionHandlingOverride=ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	GetWorld()->SpawnActor<AActor>(FlareClass,SpawnTm,SpawnParams);

	Destroy();
}

// Called every frame
void ASExplosiveBarrel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

