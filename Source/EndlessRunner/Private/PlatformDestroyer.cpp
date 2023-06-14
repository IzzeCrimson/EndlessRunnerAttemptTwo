// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformDestroyer.h"

#include "CleanupInterface.h"

// Sets default values
APlatformDestroyer::APlatformDestroyer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Collider = CreateDefaultSubobject<UBoxComponent>("Collider");
	SetRootComponent(Collider);
	
}

// Called when the game starts or when spawned
void APlatformDestroyer::BeginPlay()
{
	Super::BeginPlay();

	Collider->OnComponentBeginOverlap.AddDynamic(this, &APlatformDestroyer::OnOverlapBegin);
}

void APlatformDestroyer::OnOverlapBegin(UPrimitiveComponent* newComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ICleanupInterface* Interface = Cast<ICleanupInterface>(OtherActor);
	if (Interface)
	{
		Interface->DeleteActor(OtherActor);
	}
}

// Called every frame
void APlatformDestroyer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

