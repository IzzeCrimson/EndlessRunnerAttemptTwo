// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ENDLESSRUNNER_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health", meta = (AllowPrivateAccess = "true"))
	float DeafaultHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health", meta = (AllowPrivateAccess = "true"))
	float CurrentHealth;

	UFUNCTION(BlueprintCallable)
	void TakeDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

	
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;


	UPROPERTY(BlueprintReadOnly)
	bool bCanTakeDamage;
	
	FTimerHandle InvincibilityTimer;

	float InvincibilityDuration;

	

	UFUNCTION()
	void SetDamageBool();
};
