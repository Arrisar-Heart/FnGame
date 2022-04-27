// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "MainGM.generated.h"

UCLASS()
class FNGAME_API AMainGM : public AGameMode
{
  GENERATED_BODY()

public:
  UFUNCTION(BlueprintCallable)
  bool TryToSpawnAnimal(const FString& PathName);

  UFUNCTION(BlueprintGetter)
  FORCEINLINE TSubclassOf<class UMainUI> GetMainUIClass() const { return MainUIClass; }

  UFUNCTION(BlueprintGetter)
  FORCEINLINE class UMainUI* GetMainUI() const { return MainUI; }

  UPROPERTY(BlueprintReadWrite)
  class AFootpaths* Footpaths;

protected:
  virtual void BeginPlay() override;

private:
  UPROPERTY(EditDefaultsOnly, BlueprintGetter = GetMainUIClass)
  TSubclassOf<class UMainUI> MainUIClass;

  UPROPERTY(BlueprintGetter = GetMainUI)
  class UMainUI* MainUI;

};
