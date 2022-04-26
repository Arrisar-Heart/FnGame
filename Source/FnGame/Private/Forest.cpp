// Fill out your copyright notice in the Description page of Project Settings.

#include "Forest.h"
#include "MainGM.h"

AForest::AForest()
{
  PrimaryActorTick.bCanEverTick = true;

  Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
  RootComponent = Root;

  Paths = CreateDefaultSubobject<USceneComponent>(TEXT("Paths"));
  Paths->SetupAttachment(RootComponent);

  Ground = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
  Ground->SetupAttachment(RootComponent);
}

void AForest::PostInitializeComponents()
{
  Super::PostInitializeComponents();

  GM = GetWorld()->GetAuthGameMode<AMainGM>();
}

void AForest::BeginPlay()
{
  Super::BeginPlay();

  GM->Forest = this;
}

bool AForest::GetFootpathByName(const FString& Name, FFootpath& Footpath) const
{
  const FFootpath* RawFootpath = Footpaths.Find(Name);

  if (RawFootpath == nullptr) { return false; }

  Footpath = FFootpath(RawFootpath->Path, RawFootpath->AnimalType);

  return true;
}
