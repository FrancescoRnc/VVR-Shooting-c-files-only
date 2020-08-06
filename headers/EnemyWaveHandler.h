// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.h"
#include "EnemyWaveHandler.generated.h"

UCLASS()
class VR_SHOOTING_API AEnemyWaveHandler : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyWaveHandler();

	// Reference of the spawner, assigned during Runtime
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AEnemySpawner* ESpawnerRef;

	// Takes count of the current wave's enemies remaining in field
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CurrentWaveCount;

	// Takes count of the current wave index in field
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CurrentWaveIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector storageLocation;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// This locates and rotates enemies given some wave infos
	UFUNCTION(BlueprintCallable)
	void MakeWave(const FWaveDispositionInfo info);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void StartWaving();

	// Called when an enemy dies, updates the current wave status
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void UpdateCurrentWaveStats(AEnemyBall* const &ball);
	void UpdateCurrentWaveStats_Implementation(AEnemyBall* const &ball);

	// Called when all enemies of the current wave are defeated
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void OnWaveEmpty();
	void OnWaveEmpty_Implementation();
};
