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

  UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
  void OnSpawn();

  UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
  void OnDespawn();

  UFUNCTION(BlueprintCallable, BlueprintSetter)
  virtual void SetPath(class USplineComponent* Path = nullptr);

  UFUNCTION(BlueprintGetter)
  float GetBaseMoveSpeed() const { return BaseMoveSpeed; }

  UFUNCTION(BlueprintGetter)
  FORCEINLINE class USceneComponent* GetRoot() const { return Root; }

  UFUNCTION(BlueprintGetter)
  FORCEINLINE class UStaticMeshComponent* GetBody() const { return Body; }

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  float MoveSpeed;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  bool bMoveBackward;

protected:
  virtual void Move(float DeltaTime);

  UPROPERTY(EditAnywhere, BlueprintGetter = GetBaseMoveSpeed)
  float BaseMoveSpeed = 15.f;

  UPROPERTY(BlueprintSetter = SetPath)
  class USplineComponent* Path;

  UPROPERTY(BlueprintReadOnly)
  float PathDistance;

private:
  UPROPERTY(VisibleDefaultsOnly, BlueprintGetter = GetRoot)
  class USceneComponent* Root;

  UPROPERTY(VisibleDefaultsOnly, BlueprintGetter = GetBody)
  class UStaticMeshComponent* Body;

};
