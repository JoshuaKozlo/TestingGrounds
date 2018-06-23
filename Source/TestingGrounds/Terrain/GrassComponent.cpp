// Fill out your copyright notice in the Description page of Project Settings.

#include "GrassComponent.h"

// Sets default calues for this component's properties
UGrassComponent::UGrassComponent()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryComponentTick.bCanEverTick = false;
}

void UGrassComponent::BeginPlay()
{
	Super::BeginPlay();

	SpawnGrass();
}

void UGrassComponent::SpawnGrass()
{
	for (size_t i = 0; i < SpawnCount; i++)
	{
		FVector Location = FMath::RandPointInBox(SpawningExtents);
		AddInstance(FTransform(Location));
	}
}



