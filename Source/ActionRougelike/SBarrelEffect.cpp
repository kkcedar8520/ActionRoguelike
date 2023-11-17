// Fill out your copyright notice in the Description page of Project Settings.


#include "SBarrelEffect.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ASBarrelEffect::ASBarrelEffect()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	EffectComp=CreateDefaultSubobject<UParticleSystemComponent>("Effect");
	
}

// Called when the game starts or when spawned
void ASBarrelEffect::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASBarrelEffect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

