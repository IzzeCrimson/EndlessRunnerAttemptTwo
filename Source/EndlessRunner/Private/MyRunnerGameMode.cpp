// Fill out your copyright notice in the Description page of Project Settings.


#include "MyRunnerGameMode.h"

#include "Kismet/GameplayStatics.h"
#include "HighScoreSaveGame.h"
#include "Containers/Array.h"
#include "EndlessRunner/EndlessRunnerCharacter.h"

void AMyRunnerGameMode::BeginPlay()
{
	Super::BeginPlay();

	temporaryFloat = 0;
	

	if (UHighScoreSaveGame* LoadGameInstance = Cast<UHighScoreSaveGame>(UGameplayStatics::LoadGameFromSlot("HighScoreSlot", 0)))
	{
		
		SortArray = LoadGameInstance->HighScores;
		
	}
	// else
	// {
	// 	UHighScoreSaveGame* SaveGameInstance = Cast<UHighScoreSaveGame>(UGameplayStatics::CreateSaveGameObject(UHighScoreSaveGame::StaticClass()));
	// 	SaveGameInstance->HighScores.Add(0);
	// 	UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("HighScoreSlot"), 0);
	// }	
	

}

TArray<float> AMyRunnerGameMode::SortScore(TArray<float> array)
{

	for (int i = 0; i < array.Num(); i++)
	{
		for(int j = 0; j < array.Num() - 1; j++)
		{
			if(array[j] < array[j + 1])
			{
				temporaryFloat = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temporaryFloat;
			}
			
		}
	}

	for (int i = 0; i < array.Num(); i++)
	{
		UE_LOG(LogTemp, Warning, TEXT("HighScore: %f"), array[i]);
	}
	
	return array;
}

