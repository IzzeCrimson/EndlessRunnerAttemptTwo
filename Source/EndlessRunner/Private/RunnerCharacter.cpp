// Fill out your copyright notice in the Description page of Project Settings.


#include "RunnerCharacter.h"

#include "Obstacle.h"
#include "Components/CapsuleComponent.h"
#include "Engine/DamageEvents.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ARunnerCharacter::ARunnerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ThisCapsuleComponent = GetCapsuleComponent();

}

// Called when the game starts or when spawned
void ARunnerCharacter::BeginPlay()
{
	Super::BeginPlay();

	ThisCapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &ARunnerCharacter::OnOverlapBegin);
}

void ARunnerCharacter::OnOverlapBegin(UPrimitiveComponent* newComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->IsA(AObstacle::StaticClass()))
	{
		FDamageEvent DamageEvent;
		this->TakeDamage(1, DamageEvent, UGameplayStatics::GetPlayerController(GetWorld(), 0), OtherActor);

	}
}

// Called every frame
void ARunnerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARunnerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

