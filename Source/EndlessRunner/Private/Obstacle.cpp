// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstacle.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
AObstacle::AObstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Cube = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube"));
	
	SetRootComponent(Cube);
	
}

// Called when the game starts or when spawned
void AObstacle::BeginPlay()
{
	Super::BeginPlay();

	//Cube->OnComponentBeginOverlap.AddDynamic(this, &AObstacle::OnOverlapBegin);
}

// Called every frame
void AObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AObstacle::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	
}

