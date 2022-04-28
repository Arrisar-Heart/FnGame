// Fill out your copyright notice in the Description page of Project Settings.

#include "Footpaths.h"
#include "MainGM.h"

AFootpaths::AFootpaths()
{
  PrimaryActorTick.bCanEverTick = true;

  Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
  RootComponent = Root;
}

void AFootpaths::BeginPlay()
{
  GM = GetWorld()->GetAuthGameMode<AMainGM>();

  Super::BeginPlay();

  GM->Footpaths = this;
}

bool AFootpaths::GetFootpathByName(const FString& Name, FFootpath& Footpath) const
{
  const FFootpath* RawFootpath = Data.Find(Name);

  if (RawFootpath == nullptr) { return false; }

  Footpath = FFootpath(RawFootpath->Path, RawFootpath->AnimalType);

  return true;
}
