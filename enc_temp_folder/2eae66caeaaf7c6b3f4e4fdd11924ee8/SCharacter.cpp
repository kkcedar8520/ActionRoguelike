// Fill out your copyright notice in the Description page of Project Settings.


#include "SCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include"SInteractionComponent.h"

// Sets default values
ASCharacter::ASCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp=CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArmComp->bUsePawnControlRotation=true;
	
	SpringArmComp->SetupAttachment(RootComponent);

	CameraComp=CreateDefaultSubobject<UCameraComponent>("Camera");
	CameraComp->SetupAttachment(SpringArmComp);

	interactionComp=CreateDefaultSubobject<USInteractionComponent>("interaction");

	GetCharacterMovement()->bOrientRotationToMovement=true;



	bUseControllerRotationYaw=false;
	
}

void ASCharacter::MoveForward(float value)
{
	FRotator ControlRot=GetControlRotation();

	ControlRot.Pitch=0.0f;
	ControlRot.Roll=0.0f;
	
	AddMovementInput(ControlRot.Vector(),value);
}

void ASCharacter::MoveRight(float value)
{
	FRotator ControlRot=GetControlRotation();

	ControlRot.Pitch=0.0f;
	ControlRot.Roll=0.0f;

	FVector RightVector= FRotationMatrix(ControlRot).GetScaledAxis(EAxis::Y);
	AddMovementInput(RightVector,value);
}

// Called when the game starts or when spawned
void ASCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void ASCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward",this,&ASCharacter::MoveForward);
	
	PlayerInputComponent->BindAxis("MoveRight",this,&ASCharacter::MoveRight);
	
	PlayerInputComponent->BindAxis("Turn",this,&APawn::AddControllerYawInput);

	PlayerInputComponent->BindAxis("LookUp",this,&APawn::AddControllerPitchInput);
	

	PlayerInputComponent->BindAction("PrimaryAttack",IE_Pressed,this,&ASCharacter::PrimaryAttack);
	PlayerInputComponent->BindAction("PrimaryInteraction",IE_Pressed,this,&ASCharacter::PrimaryInteraction);
	PlayerInputComponent->BindAction("Jump",IE_Pressed,this,&ASCharacter::Jump);
	
}

void ASCharacter::PrimaryAttack()
{

	PlayAnimMontage(AttackAnimMontage);

	GetWorldTimerManager().SetTimer(TimerHandle_PrimaryAttack,this, &ASCharacter::PrimaryAttack_Timelapsed, 0.2);


	
}

void ASCharacter::PrimaryAttack_Timelapsed()
{
	FVector HandLocation = GetMesh()->GetSocketLocation("Muzzle_01");


	FTransform SpawnTm = FTransform(GetControlRotation(), HandLocation);

	FActorSpawnParameters SpawnParams;

	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	GetWorld()->SpawnActor<AActor>(ProjectileClass, SpawnTm, SpawnParams);
}

void ASCharacter::PrimaryInteraction()
{
	if(interactionComp)
	{
		interactionComp->PrimaryInteract();	
	}
	
}
