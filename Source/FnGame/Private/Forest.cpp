// Fill out your copyright notice in the Description page of Project Settings.

#include "Forest.h"
#include "MainGM.h"
#include "Components/SplineComponent.h"

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

void AForest::BeginPlay()
{
  Super::BeginPlay();

  TArray<USceneComponent*> RawComponents;
  PathsComponent->GetChildrenComponents(false, RawComponents);

  for (USceneComponent* RawComponent : RawComponents)
  {
    USplineComponent* Path = Cast<USplineComponent>(RawComponent);

    if (Path != nullptr)
    {
      Paths.Emplace(Path->GetName(), Path);
    }
  }

  GM = GetWorld()->GetAuthGameMode<AMainGM>();
}

TArray<FString> AForest::GetPaths() const
{
  TArray<FString> Keys;
  Paths.GenerateKeyArray(Keys);

  return Keys;
}

USplineComponent* AForest::GetPathByName(const FString& Name) const
{
  return Paths.FindRef(Name);
}
