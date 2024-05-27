// Fill out your copyright notice in the Description page of Project Settings.


#include "SExplosiveBarrel.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "DrawDebugHelpers.h"



// Sets default values
ASExplosiveBarrel::ASExplosiveBarrel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMeshComp=CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	StaticMeshComp->SetSimulatePhysics(true);
	StaticMeshComp->SetCollisionProfileName(UCollisionProfile::PhysicsActor_ProfileName);

	RootComponent = StaticMeshComp;

	RadialForceComp = CreateDefaultSubobject<URadialForceComponent>("Force");

	RadialForceComp->SetupAttachment(StaticMeshComp);
	
	//PostInitializeComponents()에 바인딩 해야되는이유  InitializeComponents로 컴포턴트들을 초기화한 이후에 할당해야 하기 떄문에 
	//StaticMeshComp->OnComponentHit.AddDynamic(this, &ASExplosiveBarrel::OnActorHit);


	
	RadialForceComp->Radius = 700;
	RadialForceComp->ImpulseStrength = 2500;
	RadialForceComp->bImpulseVelChange = true;

	RadialForceComp->AddCollisionChannelToAffect(ECC_WorldDynamic);
}

// Called when the game starts or when spawned
void ASExplosiveBarrel::BeginPlay()
{
	Super::BeginPlay();
	
}
void ASExplosiveBarrel::PostInitializeComponents()
{
	// Don't forget to call parent function
	Super::PostInitializeComponents();
	
	StaticMeshComp->OnComponentHit.AddDynamic(this, &ASExplosiveBarrel::OnActorHit);
}


void ASExplosiveBarrel::OnActorHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{

	RadialForceComp->FireImpulse();
	
	UE_LOG(LogTemp, Log, TEXT("OnActorHit in Explosive Barrel"));

	UE_LOG(LogTemp, Warning, TEXT("OnActor:%s, at game time:%f"), *GetNameSafe(OtherActor), GetWorld()->TimeSeconds);

	FString CombineString = FString::Printf(TEXT("Hit Actor Location : %s"), * Hit.ImpactPoint.ToString());
	

	DrawDebugString(GetWorld(), Hit.ImpactPoint, CombineString, nullptr, FColor::Green, 2.0f, true);
}


// Called every frame
void ASExplosiveBarrel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

