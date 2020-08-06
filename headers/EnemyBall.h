// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "EnemyBall.generated.h"

class AEnemySpawner;

UCLASS()
class VR_SHOOTING_API AEnemyBall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyBall();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxHealthValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CurHealthValue;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//----------------------------------------//

	// Value used to increase the general score (future use)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ScoreValue;

	UFUNCTION(BlueprintCallable)
	void DoAction();

	// This function provides the visibility of the instance
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void Despawn();

	// This function provides the visibility of the instance
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void Respawn();
	
	// This function simply moves the instance given a TVector
	UFUNCTION(BlueprintCallable)
	void Locate(const FVector& vec);

	// Used when an unused instance needs to be reused
	UFUNCTION(BlueprintCallable)
	void RestoreHealth();
};
