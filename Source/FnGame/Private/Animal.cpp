// Fill out your copyright notice in the Description page of Project Settings.

#include "Animal.h"

AAnimal::AAnimal()
{
  PrimaryActorTick.bCanEverTick = true;

  Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
  RootComponent = Root;

  Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
  Body->SetupAttachment(RootComponent);
}
