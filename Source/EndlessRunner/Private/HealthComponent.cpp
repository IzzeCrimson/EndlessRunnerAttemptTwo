// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

#include "EndlessRunner/EndlessRunnerCharacter.h"
#include "HighScoreSaveGame.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	
	DeafaultHealth = 3;
	CurrentHealth = DeafaultHealth;

	bCanTakeDamage = true;

	InvincibilityDuration = 1.f;
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

		if (CurrentHealth <= 0)
		{
			if (AEndlessRunnerCharacter* Player = Cast<AEndlessRunnerCharacter>(DamagedActor))
			{
				if (UHighScoreSaveGame* LoadGameInstance = Cast<UHighScoreSaveGame>(UGameplayStatics::LoadGameFromSlot("HighScoreSlot", 0)))
				{
					UHighScoreSaveGame* SaveGameInstance = Cast<UHighScoreSaveGame>(UGameplayStatics::CreateSaveGameObject(UHighScoreSaveGame::StaticClass()));

					if (LoadGameInstance->HighScores.Num() > 0)
					{
						//for (int i = 0; i < LoadGameInstance->HighScores.Num(); i++)
						SaveGameInstance->HighScores = LoadGameInstance->HighScores;
					}
					
					SaveGameInstance->HighScores.Add(Player->HighScore);
					UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("HighScoreSlot"), 0);
					
				}
				else
				{
					UHighScoreSaveGame* SaveGameInstance = Cast<UHighScoreSaveGame>(UGameplayStatics::CreateSaveGameObject(UHighScoreSaveGame::StaticClass()));
					SaveGameInstance->HighScores.Add(Player->HighScore);
					UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("HighScoreSlot"), 0);
				}

				//UE_LOG(LogTemp, Warning, TEXT("HighScore: %f"), SaveGameInstance->HighScores[0]);
			}
			
			DamagedActor->Destroy();
		}
		
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



