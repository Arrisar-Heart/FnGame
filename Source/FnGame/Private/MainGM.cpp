// Fill out your copyright notice in the Description page of Project Settings.

#include "MainGM.h"
#include "MainUI.h"
#include "Footpaths.h"
#include "Animal.h"

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
  if (Footpaths == nullptr) { return false; }

  FFootpath Footpath;
  if (!Footpaths->GetFootpathByName(PathName, Footpath)) { return false; }

  if (Footpath.Path == nullptr || Footpath.AnimalType == nullptr) { return false; }

  FTransform AnimalTransform = Footpath.Path->GetTransformAtSplinePoint(0, ESplineCoordinateSpace::World);
  AAnimal* Animal = GetWorld()->SpawnActor<AAnimal>(Footpath.AnimalType, AnimalTransform);

  if (Animal == nullptr) { return false; }

  Animal->OnSpawn();
  Animal->SetPath(Footpath.Path);

  return true;
}
