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

  UFUNCTION(BlueprintPure)
  TArray<FString> GetPaths() const;

  UFUNCTION(BlueprintPure)
  class USplineComponent* GetPathByName(const FString& Name) const;

  virtual void PostInitializeComponents() override;

  UFUNCTION(BlueprintGetter)
  FORCEINLINE class USceneComponent* GetRoot() const { return Root; }

  UFUNCTION(BlueprintGetter)
  FORCEINLINE class USceneComponent* GetPathsComponent() const { return PathsComponent; }

  UFUNCTION(BlueprintGetter)
  FORCEINLINE class UStaticMeshComponent* GetGround() const { return Ground; }

  UFUNCTION(BlueprintGetter)
  FORCEINLINE class AMainGM* GetGM() const { return GM; }

private:
  TMap<FString, class USplineComponent*> Paths;

  UPROPERTY(VisibleDefaultsOnly, BlueprintGetter = GetRoot)
  class USceneComponent* Root;

  UPROPERTY(VisibleDefaultsOnly, BlueprintGetter = GetPathsComponent)
  class USceneComponent* PathsComponent;

  UPROPERTY(VisibleDefaultsOnly, BlueprintGetter = GetGround)
  class UStaticMeshComponent* Ground;

  UPROPERTY(BlueprintGetter = GetGM, meta=(BlueprintProtected = "true"))
  class AMainGM* GM;

};
