// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	DeafaultHealth = 3;
	CurrentHealth = DeafaultHealth;

	bCanTakeDamage = true;

	InvincibilityDuration = 3;
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	AActor* MyOwner = GetOwner();
	if (MyOwner)
	{
		MyOwner->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::TakeDamage);
	}
}

void UHealthComponent::TakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	if (bCanTakeDamage)
	{
		CurrentHealth = CurrentHealth - Damage;
		UE_LOG(LogTemp, Warning, TEXT("Current Health is: %f"), CurrentHealth);
		bCanTakeDamage = false;
		GetWorld()->GetTimerManager().SetTimer(InvincibilityTimer, this, &UHealthComponent::SetDamageBool, InvincibilityDuration, false);
		
	}
}

void UHealthComponent::SetDamageBool()
{
	bCanTakeDamage = true;
	InvincibilityTimer.Invalidate();
	
}



