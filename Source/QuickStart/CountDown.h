// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Engine/Classes/Components/TextRenderComponent.h>
#include "CountDown.generated.h"

UCLASS()
class QUICKSTART_API ACountDown : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACountDown();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	void UpdateTimerDisplay();
	void AdvanceTimer();

	UFUNCTION(BlueprintNativeEvent)
	void CountDownHasFinished();
	virtual void CountDownHasFinished_Implementation();

public:
	UPROPERTY(EditAnywhere)
	int32 countDownTime;

	UTextRenderComponent* countDownText;
	FTimerHandle countDownTimerHandle;
};
