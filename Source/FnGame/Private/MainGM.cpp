// Fill out your copyright notice in the Description page of Project Settings.

#include "MainGM.h"
#include "MainUI.h"
#include "Animal.h"
#include "Forest.h"
#include "Footpath.h"

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

bool AMainGM::TryToSpawnAnimal(const FString& PathName) const
{
  if (Forest == nullptr) { return false; }

  UFootpath* Path = Forest->GetPathByName(PathName);

  if (Path == nullptr) { return false; }

  FTransform NewTransform = Path->GetTransformAtSplinePoint(0, ESplineCoordinateSpace::World);
  AAnimal* NewAnimal = GetWorld()->SpawnActor<AAnimal>(Path->GetAnimalType(), NewTransform);

  return true;
}
