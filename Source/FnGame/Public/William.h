// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/DefaultPawn.h"
#include "William.generated.h"

UCLASS()
class FNGAME_API AWilliam : public ADefaultPawn
{
  GENERATED_BODY()

public:
  UFUNCTION(BlueprintGetter)
  FORCEINLINE class AMainGM* GetGM() const { return GM; }

protected:
  virtual void BeginPlay() override;

  virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
  UPROPERTY(BlueprintGetter = GetGM, meta=(BlueprintProtected = "true"))
  class AMainGM* GM;

};
