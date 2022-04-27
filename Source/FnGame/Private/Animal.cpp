// Fill out your copyright notice in the Description page of Project Settings.

#include "Animal.h"
#include "Components/SplineComponent.h"

AAnimal::AAnimal()
{
  PrimaryActorTick.bCanEverTick = true;

  Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
  RootComponent = Root;

  Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
  Body->SetupAttachment(RootComponent);
}

void AAnimal::Tick(float DeltaTime)
{
  Super::Tick(DeltaTime);

  Move(DeltaTime);
}

void AAnimal::SetPath(USplineComponent* _Path)
{
  Path = _Path;
  PathDistance = 0;
}

void AAnimal::Move(float DeltaTime)
{
  if (Path == nullptr) { return; }

  PathDistance += DeltaTime * MoveSpeed;

  FVector NextLocation = Path->GetLocationAtDistanceAlongSpline(PathDistance, ESplineCoordinateSpace::World);
  FQuat NextRotation = FVector(Path->GetWorldDirectionAtDistanceAlongSpline(PathDistance) * (bMoveBackward ? -1 : 1)).Rotation().Quaternion();

  SetActorLocationAndRotation(NextLocation, NextRotation);

  if (PathDistance >= Path->GetSplineLength())
  {
    OnDespawn();
    SetPath();
  }
}
