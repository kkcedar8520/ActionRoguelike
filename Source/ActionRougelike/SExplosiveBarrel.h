// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"
#include "SExplosiveBarrel.generated.h"

class UProjectileMovementComponent;
class URadialForceComponent;
class UStaticMeshComponent;
class ASExplosiveEffect;
UCLASS()
class ACTIONROUGELIKE_API ASExplosiveBarrel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASExplosiveBarrel();

protected:
	// Called when the game starts or when spawned
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	URadialForceComponent* RadialForceComp;

	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent* FireEffectComp;
	
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* StaticMeshComp;
	
	UFUNCTION()
	void OnActorHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	virtual void PostInitializeComponents()override;

	virtual void BeginPlay() override;



	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
