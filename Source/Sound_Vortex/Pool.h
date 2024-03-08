// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PooledObject.h"
#include "Pool.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SOUND_VORTEX_API UPool : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPool();

	UFUNCTION(BlueprintCallable, Category = "Pool")
		APooledObject* SpawnPooledObject();

	UPROPERTY(EditAnywhere, Category = "Pool")
		TSubclassOf<class APooledObject> PooledObjectSubclass;

	UPROPERTY(EditAnywhere, Category = "Pool")
		int PoolSize = 20;

	UPROPERTY(EditAnywhere, Category = "Pool")
		float PooledObjectLifeSpan = 0.0f;

	UFUNCTION()
	void OnPooledObjectDespawn(APooledObject* PoolActor);


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	TArray<APooledObject*> Pool;
	TArray<int> SpawnedPoolIndexes;


		
};
