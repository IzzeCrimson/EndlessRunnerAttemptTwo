// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Character.h"
#include "RunnerCharacter.generated.h"

UCLASS()
class ENDLESSRUNNER_API ARunnerCharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = CapsuleCollider, meta = (AllowPrivateAccess = "true"))
	UCapsuleComponent* ThisCapsuleComponent;
	
public:
	// Sets default values for this character's properties
	ARunnerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* newComp, class AActor* OtherActor,class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	                    bool bFromSweep, const FHitResult& SweepResult);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(EditAnywhere, Category = "Collision", meta = (AllowPrivateAccess = "true"))
	UBoxComponent* EvadeCollider;

	// UPROPERTY(EditAnywhere, Category = "Collision", meta = (AllowPrivateAccess = "true"))
	// UBoxComponent* LowerCollider;
};
