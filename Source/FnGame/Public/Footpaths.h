// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Components/SplineComponent.h"
#include "GameFramework/Actor.h"
#include "Footpaths.generated.h"

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
class FNGAME_API AFootpaths : public AActor
{
  GENERATED_BODY()

public:
  AFootpaths();

  UFUNCTION(BlueprintPure)
  bool GetFootpathByName(const FString& Name, FFootpath& Footpath) const;

  virtual void PostInitializeComponents() override;

  UFUNCTION(BlueprintGetter)
  FORCEINLINE class USceneComponent* GetRoot() const { return Root; }

  UFUNCTION(BlueprintGetter)
  FORCEINLINE class AMainGM* GetGM() const { return GM; }

protected:
  virtual void BeginPlay() override;

  UFUNCTION(BlueprintCallable, meta=(BlueprintProtected = "true"))
  void AddFootpath(const FFootpath& Footpath) { Data.Emplace(Footpath.Path->GetName(), Footpath); }

  UPROPERTY(BlueprintReadWrite, meta=(BlueprintProtected = "true"))
  TMap<FString, FFootpath> Data;

private:
  UPROPERTY(VisibleDefaultsOnly, BlueprintGetter = GetRoot)
  class USceneComponent* Root;

  UPROPERTY(BlueprintGetter = GetGM, meta=(BlueprintProtected = "true"))
  class AMainGM* GM;

};
