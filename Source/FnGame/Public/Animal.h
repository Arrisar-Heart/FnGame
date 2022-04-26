// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Animal.generated.h"

UCLASS()
class FNGAME_API AAnimal : public AActor
{
  GENERATED_BODY()

public:
  AAnimal();

  UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
  void OnSpawn();

  UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
  void OnDespawn();

  UFUNCTION(BlueprintGetter)
  FORCEINLINE class USceneComponent* GetRoot() const { return Root; }

  UFUNCTION(BlueprintGetter)
  FORCEINLINE class UStaticMeshComponent* GetBody() const { return Body; }

private:
  UPROPERTY(VisibleDefaultsOnly, BlueprintGetter = GetRoot)
  class USceneComponent* Root;

  UPROPERTY(VisibleDefaultsOnly, BlueprintGetter = GetBody)
  class UStaticMeshComponent* Body;

};
