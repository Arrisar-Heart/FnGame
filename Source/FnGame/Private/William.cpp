// Fill out your copyright notice in the Description page of Project Settings.

#include "William.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"
#include "MainGM.h"

void AWilliam::BeginPlay()
{
  GM = GetWorld()->GetAuthGameMode<AMainGM>();

  Super::BeginPlay();
}

void AWilliam::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
  Super::SetupPlayerInputComponent(PlayerInputComponent);

  FInputActionBinding AB;

  AB = FInputActionBinding("1", IE_Released);
  AB.ActionDelegate.GetDelegateForManualSet().BindLambda([this]() { GM->TryToSpawnAnimal("Path_1"); });
  PlayerInputComponent->AddActionBinding(AB);

  AB = FInputActionBinding("2", IE_Released);
  AB.ActionDelegate.GetDelegateForManualSet().BindLambda([this]() { GM->TryToSpawnAnimal("Path_2"); });
  PlayerInputComponent->AddActionBinding(AB);

  AB = FInputActionBinding("3", IE_Released);
  AB.ActionDelegate.GetDelegateForManualSet().BindLambda([this]() { GM->TryToSpawnAnimal("Path_3"); });
  PlayerInputComponent->AddActionBinding(AB);

  AB = FInputActionBinding("Exit", IE_Released);
  AB.ActionDelegate.GetDelegateForManualSet().BindLambda([this]()
  {
    UKismetSystemLibrary::QuitGame(GetWorld(), UGameplayStatics::GetPlayerController(GetWorld(), 0), EQuitPreference::Quit, false);
  });
  PlayerInputComponent->AddActionBinding(AB);
}
