// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tile.generated.h"

class UActorPool;

UCLASS()
class TESTINGGROUNDS_API ATile : public AActor
{

	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY(EditDefaultsOnly, Category = "Sizing")
	FVector MinExtent;

	UPROPERTY(EditDefaultsOnly, Category = "Sizing")
	FVector MaxExtent;
	
public:	
	// Sets default values for this actor's properties
	ATile();

	UFUNCTION(BlueprintCallable, Category = "Weapons")
	void PlaceActors(TSubclassOf<AActor> ToSpawn, int MinSpawn = 1, int MaxSpawn = 1, float Radius = 500, float MinScale = 1, float MaxScale = 1);

public:	
	// Called every frame

	UFUNCTION(BlueprintCallable, Category = "Pool")
	void SetPool(UActorPool* Pool);

private:
	void PositionNavMeshBoundsVolume();

	bool FindEmptyLocation(FVector& OutLocation, float Radius);

	void PlaceActor(TSubclassOf<AActor> ToSpawn, FVector SpawnPoint, float Rotation, float Scale);

	bool CanSpawnAtLocation(FVector Location, float Radius);

	UActorPool* Pool;

	AActor* NavMeshBoundsVolume;
};
