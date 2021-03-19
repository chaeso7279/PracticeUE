// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CameraSturcts.h"
#include "CameraDirector.generated.h"

UCLASS()
class QUICKSTART_API ACameraDirector : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACameraDirector();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	/*UPROPERTY(EditAnywhere)
	AActor* camOne;
	UPROPERTY(EditAnywhere)
	AActor* camTwo;*/
	UPROPERTY(EditAnywhere)
	float timeToNextCameraChange;
	
	UPROPERTY(EditAnywhere)
	TArray<FCameraStruct> arrCameras;

	int8 idxCurCam;
};
