// Fill out your copyright notice in the Description page of Project Settings.


#include "CleanupInterface.h"


// Add default functionality here for any ICleanupInterface functions that are not pure virtual.
void ICleanupInterface::DeleteActor(AActor* ActorToDelete)
{
	UE_LOG(LogTemp, Warning, TEXT("Hello"));
}
