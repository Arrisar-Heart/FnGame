// Fill out your copyright notice in the Description page of Project Settings.

#include "Forest.h"
#include "MainGM.h"
#include "Footpath.h"

AForest::AForest()
{
  PrimaryActorTick.bCanEverTick = true;

  Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
  RootComponent = Root;

  PathsComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Paths"));
  PathsComponent->SetupAttachment(RootComponent);

  Ground = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
  Ground->SetupAttachment(RootComponent);
}

void AForest::PostInitializeComponents()
{
  Super::PostInitializeComponents();

  TArray<USceneComponent*> RawComponents;
  PathsComponent->GetChildrenComponents(false, RawComponents);

  for (USceneComponent* RawComponent : RawComponents)
  {
    UFootpath* Path = Cast<UFootpath>(RawComponent);

    if (Path != nullptr)
    {
      Paths.Emplace(Path->GetName(), Path);
    }
  }

  GM = GetWorld()->GetAuthGameMode<AMainGM>();
}

void AForest::BeginPlay()
{
  Super::BeginPlay();

  GM->Forest = this;
}

TArray<FString> AForest::GetPaths() const
{
  TArray<FString> Keys;
  Paths.GenerateKeyArray(Keys);

  return Keys;
}

UFootpath* AForest::GetPathByName(const FString& Name) const
{
  return Paths.FindRef(Name);
}
