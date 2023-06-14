// Fill out your copyright notice in the Description page of Project Settings.


#include "SpeedManager.h"

// Sets default values
ASpeedManager::ASpeedManager()
{
 	// Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASpeedManager::BeginPlay()
{
	Super::BeginPlay();
	DifficultySpeed = 500;
}

// Called every frame
void ASpeedManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DifficultySpeed += 0.1f;
}

