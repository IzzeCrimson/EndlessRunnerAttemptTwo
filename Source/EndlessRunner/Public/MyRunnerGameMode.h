// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyRunnerGameMode.generated.h"

/**
 * 
 */
UCLASS()
class ENDLESSRUNNER_API AMyRunnerGameMode : public AGameModeBase
{
	GENERATED_BODY()

	virtual void BeginPlay() override;

	
public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<float> SortArray;
	
	UFUNCTION(BlueprintCallable)
	TArray<float> SortScore(TArray<float> array);

private:
	float temporaryFloat;
};
