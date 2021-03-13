// Fill out your copyright notice in the Description page of Project Settings.


#include "FloatingActor.h"
#include "QuickStart.h"

// Sets default values
AFloatingActor::AFloatingActor()
	:floatingSpeed(1.f, 1.f, 1.f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(MyLogCategory, Log, TEXT("MyLog"));
	
}

// Called every frame
void AFloatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector newLocation = GetActorLocation();
	float deltaX = (FMath::Sin(runningTime.X + DeltaTime * floatingSpeed.X) - FMath::Sin(runningTime.X));
	float deltaY = (FMath::Sin(runningTime.Y + DeltaTime * floatingSpeed.Y) - FMath::Sin(runningTime.Y));
	float deltaZ = (FMath::Sin(runningTime.Z + DeltaTime * floatingSpeed.Z) - FMath::Sin(runningTime.Z));

	newLocation += FVector(deltaX, deltaY, deltaZ) * 20.f;
	runningTime += DeltaTime * floatingSpeed;
	
	SetActorLocation(newLocation);
}

