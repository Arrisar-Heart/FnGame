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

  virtual void Tick(float DeltaTime) override;

  UFUNCTION(BlueprintGetter)
  FORCEINLINE class UStaticMeshComponent* GetBody() const { return Body; }

protected:
  virtual void BeginPlay() override;

private:
  UPROPERTY(VisibleDefaultsOnly, BlueprintGetter = GetBody)
  class UStaticMeshComponent* Body;

};
