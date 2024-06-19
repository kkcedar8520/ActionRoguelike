// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class USInteractionComponent;

UCLASS()
class ACTIONROUGELIKE_API ASCharacter : public ACharacter
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere,Category="Attack")
	TSubclassOf<AActor> ProjectileClass;
	UPROPERTY(EditAnywhere,Category="Attack")
	UAnimMontage* AttackAnimMontage;

	UPROPERTY(EditAnywhere,Category="Attack")
	TSubclassOf<AActor> UltimateClass;

	FTimerHandle TimerHandle_PrimaryAttack;
	
public:
	// Sets default values for this character's properties
	ASCharacter();

protected:
	// Called when the game starts or when spawned

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComp;
	
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere)
	USInteractionComponent* interactionComp;
	
	

	void MoveForward(float value);
	void MoveRight(float value);
	virtual void BeginPlay() override;

	void PrimaryAttack();
	void PrimaryAttack_Timelapsed();
	void PrimaryInteraction();

	void Ultimate();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
