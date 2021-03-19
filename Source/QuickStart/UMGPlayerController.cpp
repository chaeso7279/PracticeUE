// Fill out your copyright notice in the Description page of Project Settings.


#include "UMGPlayerController.h"

void AUMGPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// 게임과 UI에 입력을 받도록 설정
	SetInputMode(FInputModeGameAndUI());
}