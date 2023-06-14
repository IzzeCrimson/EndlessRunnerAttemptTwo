// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EndlessRunner/EndlessRunnerCharacter.h"
#include "GameFramework/Pawn.h"
#include "InputReciever.generated.h"

UCLASS()
class ENDLESSRUNNER_API AInputReciever final : public APawn
{
	GENERATED_BODY()

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;
	
	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* JumpAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* SecondJumpAction;
	
	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* SecondMoveAction;


	
public:
	// Sets default values for this pawn's properties
	AInputReciever();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Players", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<ACharacter> FirstPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Players", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<ACharacter> SecondPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Players", meta = (AllowPrivateAccess = "true"))
	AActor* FirstSpawned;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Players", meta = (AllowPrivateAccess = "true"))
	AActor* SecondSpawned;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	void CustomMove(const FInputActionValue& Value);
	void SecondCustomMove(const FInputActionValue& Value);

	FVector MyLocation;
	FVector MyLocationOffset;
	FRotator MyRotation;
};
