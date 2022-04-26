// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/DefaultPawn.h"
#include "SuperPawn.generated.h"

UCLASS()
class FNGAME_API ASuperPawn : public ADefaultPawn
{
  GENERATED_BODY()

public:
  virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
