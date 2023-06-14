// Fill out your copyright notice in the Description page of Project Settings.


#include "MovablePlatform.h"

// Sets default values
AMovablePlatform::AMovablePlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CurrentLocation = this->GetActorLocation();
	Speed = 500.0f;

	bIsActive = true;
	
}

// Called when the game starts or when spawned
void AMovablePlatform::BeginPlay()
{
	Super::BeginPlay();
	if (CurrentLocation == FVector(0, 0, 0))
	{
		CurrentLocation = this->GetActorLocation();
		
	}
	
}

// Called every frame
void AMovablePlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsActive)
	{
		CurrentLocation.Y -= Speed * DeltaTime;
		SetActorLocation(CurrentLocation);
		
	}

}

