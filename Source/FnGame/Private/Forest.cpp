// Fill out your copyright notice in the Description page of Project Settings.

#include "Forest.h"
#include "MainGM.h"
#include "Components/SplineComponent.h"

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
