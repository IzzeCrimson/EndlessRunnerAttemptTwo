// Fill out your copyright notice in the Description page of Project Settings.


#include "InputReciever.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "EndlessRunner/EndlessRunnerCharacter.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AInputReciever::AInputReciever()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	
}


// Called when the game starts or when spawned
void AInputReciever::BeginPlay()
{
	Super::BeginPlay();

	MyLocation = FVector(0, 40, 120);
	MyLocationOffset = FVector(50, 0, 0);
	MyRotation = FRotator(0, 90, 0);
	
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}

	FirstSpawned = GetWorld()->SpawnActor(FirstPlayer, &MyLocation, &MyRotation);
	SecondSpawned = GetWorld()->SpawnActor(SecondPlayer, &MyLocation, &MyRotation);
	
}

// Called every frame
void AInputReciever::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}

// // Called to bind functionality to input
void AInputReciever::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
			
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AInputReciever::CustomMove);
		EnhancedInputComponent->BindAction(SecondMoveAction, ETriggerEvent::Triggered, this, &AInputReciever::SecondCustomMove);
	}

}


void AInputReciever::CustomMove(const FInputActionValue& Value)
{

	FVector2D MovementVector = Value.Get<FVector2D>();
	
	FirstSpawned->SetActorLocation(FirstSpawned->GetActorLocation() + FVector((MovementVector.X * -1) * 5, 0, 0));

	if (FirstSpawned->GetActorLocation().X > 330)
	{
		FirstSpawned->SetActorLocation(FVector(330, FirstSpawned->GetActorLocation().Z, FirstSpawned->GetActorLocation().Y));	
	}

	if (FirstSpawned->GetActorLocation().X < -330)
	{
		FirstSpawned->SetActorLocation(FVector(-330, FirstSpawned->GetActorLocation().Z, FirstSpawned->GetActorLocation().Y));	
	}
}

void AInputReciever::SecondCustomMove(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();
	SecondSpawned->SetActorLocation(SecondSpawned->GetActorLocation() + FVector((MovementVector.X * -1) * 5, 0, 0));

	if (SecondSpawned->GetActorLocation().X > 330)
	{
		SecondSpawned->SetActorLocation(FVector(330, SecondSpawned->GetActorLocation().Z, SecondSpawned->GetActorLocation().Y));	
	}

	if (SecondSpawned->GetActorLocation().X < -330)
	{
		SecondSpawned->SetActorLocation(FVector(-330, SecondSpawned->GetActorLocation().Z, SecondSpawned->GetActorLocation().Y));	
	}
}

