// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraDirector.h"
#include <Kismet/GameplayStatics.h>

// Sets default values
ACameraDirector::ACameraDirector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACameraDirector::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACameraDirector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*const float timeChangeCamera = 2.f;
	const float timeSmoothBlend = 0.75f;

	timeToNextCameraChange -= DeltaTime;
	if (timeToNextCameraChange <= 0.f)
	{
		timeToNextCameraChange += timeChangeCamera;

		APlayerController* controller = UGameplayStatics::GetPlayerController(this, 0);
		if (camOne != nullptr && (controller->GetViewTarget() != camOne))
			controller->SetViewTarget(camOne);
		else if (camTwo != nullptr && (controller->GetViewTarget() != camTwo))
			controller->SetViewTargetWithBlend(camTwo, timeSmoothBlend);
	}*/
	
	arrCameras[idxCurCam]->timeTo
}

