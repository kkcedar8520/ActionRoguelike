// Fill out your copyright notice in the Description page of Project Settings.


#include "SInteractionComponent.h"

#include "SGamePlayInterface.h"

void USInteractionComponent::PrimaryInteract()
{
	

	FCollisionObjectQueryParams ObjectQuerryParams;
	ObjectQuerryParams.AddObjectTypesToQuery(ECC_WorldDynamic);

	AActor* Owner=GetOwner();


	
	FVector EyeLocation;
	FRotator EyeRotation;
	
	Owner->GetActorEyesViewPoint(EyeLocation,EyeRotation);

	FVector End=EyeLocation+(EyeRotation.Vector()*1000);
	
	FHitResult Hit;
	GetWorld()->LineTraceSingleByObjectType(Hit,EyeLocation,End,ObjectQuerryParams);

	AActor* HitActor =Hit.GetActor();
	if(HitActor)
	{
		if(HitActor->Implements<USGamePlayInterface>())
		{
			APawn* MyPawn=Cast<APawn>(Owner);

			ISGamePlayInterface::Execute_Interact(HitActor,MyPawn);
		}
	}

	

}


// Sets default values for this component's properties
USInteractionComponent::USInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;


	// ...
}


// Called when the game starts
void USInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

