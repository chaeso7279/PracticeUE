// Fill out your copyright notice in the Description page of Project Settings.


#include "CountDown.h"

// Sets default values
ACountDown::ACountDown()
	:countDownTime(3)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	countDownText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Countdown Text"));
	countDownText->SetHorizontalAlignment(EHTA_Center);
	countDownText->SetWorldSize(150.f);
}

// Called when the game starts or when spawned
void ACountDown::BeginPlay()
{
	Super::BeginPlay();
	
	UpdateTimerDisplay();
	GetWorldTimerManager().SetTimer(countDownTimerHandle, this, &ACountDown::AdvanceTimer, 1.f, true);
}

void ACountDown::UpdateTimerDisplay()
{
	countDownText->SetText(FString::FromInt(FMath::Max(countDownTime, 0)));
}

void ACountDown::AdvanceTimer()
{
	--countDownTime;
	UpdateTimerDisplay();

	if (countDownTime < 1) // Time이 0이 됨
	{
		GetWorldTimerManager().ClearTimer(countDownTimerHandle);
		CountDownHasFinished();
	}
}

void ACountDown::CountDownHasFinished_Implementation()
{
	countDownText->SetText(TEXT("Go!"));
}