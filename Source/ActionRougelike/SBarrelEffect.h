// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SBarrelEffect.generated.h"

class UParticleSystemComponent;
UCLASS()
class ACTIONROUGELIKE_API ASBarrelEffect : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASBarrelEffect();

protected:
	// Called when the game starts or when spawned

	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent* EffectComp;
	
	
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
