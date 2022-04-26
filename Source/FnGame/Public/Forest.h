// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Components/SplineComponent.h"
#include "GameFramework/Actor.h"
#include "Forest.generated.h"

USTRUCT(BlueprintType)
struct FFootpath
{
  GENERATED_BODY()

  FORCEINLINE FFootpath() { }
  explicit FORCEINLINE FFootpath(USplineComponent* _Path, TSubclassOf<class AAnimal> _AnimalType) : Path(_Path), AnimalType(_AnimalType) { }

  UPROPERTY(BlueprintReadWrite)
  USplineComponent* Path;

  UPROPERTY(BlueprintReadWrite)
  TSubclassOf<class AAnimal> AnimalType;

};

UCLASS()
class FNGAME_API AForest : public AActor
{
  GENERATED_BODY()

public:
  AForest();

  UFUNCTION(BlueprintPure)
  FFootpath GetFootpathByName(const FString& Name) const { return *Footpaths.Find(Name); }

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

  UFUNCTION(BlueprintCallable, meta=(BlueprintProtected = "true"))
  void AddFootpath(const FFootpath& Footpath) { Footpaths.Emplace(Footpath.Path->GetName(), Footpath); }

  UPROPERTY(BlueprintReadWrite, meta=(BlueprintProtected = "true"))
  TMap<FString, FFootpath> Footpaths;

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
