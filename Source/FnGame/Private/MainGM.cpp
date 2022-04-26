// Fill out your copyright notice in the Description page of Project Settings.

#include "MainGM.h"
#include "MainUI.h"
#include "Forest.h"

void AMainGM::BeginPlay()
{
  Super::BeginPlay();

  if (MainUIClass != nullptr)
  {
    MainUI = Cast<UMainUI>(CreateWidget(GetWorld(), MainUIClass));

    if (MainUI != nullptr)
    {
      MainUI->AddToViewport();
    }
  }
}

bool AMainGM::TryToSpawnAnimal(const FString& PathName)
{
  if (Forest == nullptr) { return false; }

  FFootpath Footpath;
  if (!Forest->GetFootpathByName(PathName, Footpath)) { return false; }

  return true;
}
