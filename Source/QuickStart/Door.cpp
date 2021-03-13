// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"

// Sets default values
ADoor::ADoor()
	:closeTime(3.f),
	bOpen(false)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	doorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door Mesh"));
	RootComponent = doorMesh;
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	
	oriRotation = GetActorRotation();
	GetWorldTimerManager().SetTimer(doorTimerHandle, this, &ADoor::Open, 0.03f, true);
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	doorDeltaTime += DeltaTime;
}

void ADoor::Open()
{
	if (!bOpen)
	{
		bOpen = true;
		doorDeltaTime = 0.f;
	}

	FRotator rotation = oriRotation + FRotator(0.f, FMath::Lerp(0.f, 90.f, doorDeltaTime), 0.f);
	SetActorRotation(rotation);
	if (doorDeltaTime >= 1.f)
	{
		GetWorldTimerManager().ClearTimer(doorTimerHandle);
		GetWorldTimerManager().SetTimer(doorTimerHandle, this, &ADoor::Close, 0.03f, true);
	}
}

void ADoor::Close()
{
	if (bOpen)
	{
		bOpen = false;
		doorDeltaTime = 0.f;
	}

	FRotator rotation = oriRotation + FRotator(0.f, FMath::Lerp(90.f, 0.f, doorDeltaTime), 0.f);
	SetActorRotation(rotation);
	if (doorDeltaTime >= 1.f)
		GetWorldTimerManager().ClearTimer(doorTimerHandle);
}

