// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Chaos/CollisionResolution.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "PlatformSpawner.generated.h"

UCLASS()
class ENDLESSRUNNER_API APlatformSpawner : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Platform Components", meta = (AllowPrivateAccess = "true"))
	UBoxComponent* BoxCollider;
	
public:	
	// Sets default values for this actor's properties
	APlatformSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	
	UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	void SpawnPlatform();

private:
	UPROPERTY(EditAnywhere, Category = "Platform Components", meta = (AllowPrivateAccess = "true"))
	TArray<TSubclassOf<AActor>> TemplatePlatforms;
	
	float RandomNumber;
	
	FVector Location;
	FVector LocationOffset;
	FRotator Rotation;

	
};
