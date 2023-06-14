// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CleanupInterface.h"
#include "MovablePlatform.generated.h"

UCLASS()
class ENDLESSRUNNER_API AMovablePlatform : public AActor, public ICleanupInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovablePlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	bool bIsActive;


private:
	FVector CurrentLocation;
	float Speed;
	
};
