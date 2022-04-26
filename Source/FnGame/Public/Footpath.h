// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SplineComponent.h"
#include "Footpath.generated.h"

UCLASS(ClassGroup=Utility, ShowCategories = (Mobility), HideCategories = (Physics, Collision, Lighting, Rendering, Mobile), meta=(BlueprintSpawnableComponent))
class FNGAME_API UFootpath : public USplineComponent
{
  GENERATED_BODY()

public:
  UFUNCTION(BlueprintGetter)
  FORCEINLINE TSubclassOf<class AAnimal> GetAnimalType() const { return AnimalType; }

private:
  UPROPERTY(EditDefaultsOnly, BlueprintGetter = GetAnimalType)
  TSubclassOf<class AAnimal> AnimalType;

};
