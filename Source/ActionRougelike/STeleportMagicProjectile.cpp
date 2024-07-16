// Fill out your copyright notice in the Description page of Project Settings.


#include "STeleportMagicProjectile.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"

void ASTeleportMagicProjectile::BeginPlay()
{
	Super::BeginPlay();


	GetWorldTimerManager().SetTimer(TimerHandle_Teleport, this, &ASTeleportMagicProjectile::Teleport, 0.2);


	

}


void ASTeleportMagicProjectile::Teleport()
{

 
	Explode();
	

}

void ASTeleportMagicProjectile::Teleport_Timelapsed()
{
	FVector Location = GetActorLocation();
	FRotator Rotator = GetActorRotation();


	AActor* AInstigator = GetInstigator();

	AInstigator->TeleportTo(Location, Rotator);

	Destroy();

}

void ASTeleportMagicProjectile::PostInitializeComponents()
{
	// Don't forget to call parent function
	Super::PostInitializeComponents();



}

void ASTeleportMagicProjectile::Explode_Implementation()
{

		GetWorldTimerManager().ClearTimer(TimerHandle_Teleport);

		UGameplayStatics::SpawnEmitterAtLocation(this, ImpactVFX, GetActorLocation(), GetActorRotation());

		EffectComp->DeactivateSystem();
		MovementComp->StopMovementImmediately();

		SetActorEnableCollision(false);
	
		GetWorldTimerManager().SetTimer(TimerHandle_Teleport, this, &ASTeleportMagicProjectile::Teleport_Timelapsed, 0.2);
}

