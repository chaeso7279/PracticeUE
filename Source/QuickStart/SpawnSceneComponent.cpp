// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnSceneComponent.h"

// Sets default values for this component's properties
USpawnSceneComponent::USpawnSceneComponent()
	:DestroyTimer(3.f)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	for (int i = 0; i < 3; ++i)
	{
		UStaticMeshComponent* Child = CreateDefaultSubobject<UStaticMeshComponent>(FName(TEXT("Child"), i));
		Child->SetupAttachment(this);
		static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone"));
		if (SphereVisualAsset.Succeeded())
		{
			Child->SetStaticMesh(SphereVisualAsset.Object);
		}

		float radian = (2.f * PI) / 3.f;
		radian *= i;
		FVector location = FVector(FMath::Cos(radian), FMath::Sin(radian), 0.f) * 100.f;
		Child->SetRelativeLocation(location);
		Childs.Add(Child);
	}
}


// Called when the game starts
void USpawnSceneComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USpawnSceneComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	DestroyTimer -= DeltaTime;
	if (DestroyTimer < 0.f)
	{
		for (UStaticMeshComponent* pChild : Childs)
			pChild->DestroyComponent();
		DestroyComponent();
	}

}

