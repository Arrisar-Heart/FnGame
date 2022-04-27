// Fill out your copyright notice in the Description page of Project Settings.

#include "Animal.h"
#include "Components/SplineComponent.h"

AAnimal::AAnimal()
{
  PrimaryActorTick.bCanEverTick = true;

  MoveSpeed = BaseMoveSpeed;

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
  FVector NextDirection = FVector(Path->GetWorldDirectionAtDistanceAlongSpline(PathDistance) * (MoveSpeed >= 0 ? 1 : -1) * (bMoveBackward ? -1 : 1));

  SetActorLocationAndRotation(NextLocation, NextDirection.Rotation().Quaternion());

  if (PathDistance >= Path->GetSplineLength())
  {
    OnDespawn();
    SetPath();
  }
}
