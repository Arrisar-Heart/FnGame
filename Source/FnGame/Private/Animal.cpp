// Fill out your copyright notice in the Description page of Project Settings.

#include "Animal.h"

AAnimal::AAnimal()
{
  PrimaryActorTick.bCanEverTick = true;

  Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
  RootComponent = Body;
}

void AAnimal::BeginPlay()
{
  Super::BeginPlay();
}

void AAnimal::Tick(float DeltaTime)
{
  Super::Tick(DeltaTime);
}
