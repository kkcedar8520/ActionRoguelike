// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SProjectileBase.h"
#include "STeleportMagicProjectile.generated.h"

/**
 * 
 */
class UParticleSystemComponent;
UCLASS()
class ACTIONROUGELIKE_API ASTeleportMagicProjectile : public ASProjectileBase
{
	GENERATED_BODY()
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UParticleSystemComponent* ExplosiveEffectComp;

	FTimerHandle TimerHandle_Teleport;

	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;
	virtual void Explode_Implementation() override;



	UFUNCTION(BlueprintCallable)
	void Teleport();

	void Teleport_Timelapsed();

};
