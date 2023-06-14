# EndlessRunnerAttemptTwo

# EndlessRunner
## Part 1
The assignment says that I am supposed "show how I have created the system", I'm unsure what "show" means here. Am I just supposed to explain what and how I have used functions in C++ or show code snippets from the project?

### Stuff I have used in the Project
**Heads up! I wouldn't call the things I have made effective since it's more basic things than advanced.**

#### HealthComponent and Timer
I could start with the HealthComponent. I have created a simple HealthComponent which is attached to the ThirdPersonCharacter (have not made my own character yet). In the HealthComponent.cpp I bind a TakeDamage method to the OnTakeAnyDamge delegate.

In HealthComponent.cpp

```
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	AActor* MyOwner = GetOwner();
	if (MyOwner)
	{
		MyOwner->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::TakeDamage);
	}
}

```

Which gets called when the player collides with a blueprint templated based on the class Obstacle.

In EndlessRunnerCharacter.cpp

```
void AEndlessRunnerCharacter::OnOverlapBegin(UPrimitiveComponent* newComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	//UE_LOG(LogTemp, Warning, TEXT("Other Actor is: %s"), *OtherActor->GetName());
	if (OtherActor->IsA(AObstacle::StaticClass()))
	{
		FDamageEvent DamageEvent;
		this->TakeDamage(1, DamageEvent, UGameplayStatics::GetPlayerController(GetWorld(), 0), OtherActor);

	}
}

```

And whenever the player takes damage I set a bool called **bCantakeDamage** to false to control when the player can take damage. And when the bool is set to false I start a timer which turns to bool to true after x amount of time.

In HealthComponent.cpp

```
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

```

#### Spawning and "Removing" Platforms

To spawn platforms to the world I have an Actor based on the SpawnPlatform class which spawns 1 out of 6 platforms templates stored in a TArray on top of its location and when the platform stops overlapping with the PlatformSpawner it spawns a new platform at its location.

When it comes to removing/deleting the platforms I have a large collider placed behind the player. Whenever an object overlaps with the collider it checks if the collider has the interface called **CleanupInterface** and if it has the interface runs a method destroying the collided platform. I plan on changing this to Object Pooling but wanted to see if I could get interfaces to work this gives me the result but I'm unsure if it's done correctly or not. 

In PlatformDestroyer.cpp

```
void APlatformDestroyer::OnOverlapBegin(UPrimitiveComponent* newComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ICleanupInterface* Interface = Cast<ICleanupInterface>(OtherActor);
	if (Interface)
	{
		Interface->DeleteActor(OtherActor);
	}
}
```



