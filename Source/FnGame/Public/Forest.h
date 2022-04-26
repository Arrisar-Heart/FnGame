// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Forest.generated.h"

UCLASS()
class FNGAME_API AForest : public AActor
{
  GENERATED_BODY()

public:
  AForest();

  virtual void PostInitializeComponents() override;

  UFUNCTION(BlueprintGetter)
  FORCEINLINE class USceneComponent* GetRoot() const { return Root; }

  UFUNCTION(BlueprintGetter)
  FORCEINLINE class USceneComponent* GetPaths() const { return Paths; }

  UFUNCTION(BlueprintGetter)
  FORCEINLINE class UStaticMeshComponent* GetGround() const { return Ground; }

  UFUNCTION(BlueprintGetter)
  FORCEINLINE class AMainGM* GetGM() const { return GM; }

protected:
  virtual void BeginPlay() override;

private:
  UPROPERTY(VisibleDefaultsOnly, BlueprintGetter = GetRoot)
  class USceneComponent* Root;

  UPROPERTY(VisibleDefaultsOnly, BlueprintGetter = GetPaths)
  class USceneComponent* Paths;

  UPROPERTY(VisibleDefaultsOnly, BlueprintGetter = GetGround)
  class UStaticMeshComponent* Ground;

  UPROPERTY(BlueprintGetter = GetGM, meta=(BlueprintProtected = "true"))
  class AMainGM* GM;

};
