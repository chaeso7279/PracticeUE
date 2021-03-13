// Fill out your copyright notice in the Description page of Project Settings.


#include "Fire.h"

// Sets default values
AFire::AFire()
	:fireFuel(5)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	fireParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Fire Particle"));
	RootComponent = fireParticle;
}

// Called when the game starts or when spawned
void AFire::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(fireTimerHandle, this, &AFire::Combustion, 1.f, true);
}

void AFire::Combustion()
{
	--fireFuel;
	if (fireFuel < 1)
		OffFire();
}

void AFire::OffFire()
{
	GetWorldTimerManager().ClearTimer(fireTimerHandle);
	fireParticle->DeactivateSystem();
}
