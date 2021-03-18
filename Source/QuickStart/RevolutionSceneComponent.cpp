// Fill out your copyright notice in the Description page of Project Settings.


#include "RevolutionSceneComponent.h"

// Sets default values for this component's properties
URevolutionSceneComponent::URevolutionSceneComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	UStaticMeshComponent* meshSphere = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshSphere"));
	meshSphere->SetupAttachment(this);
	meshSphere->SetRelativeLocation(FVector(0.f, 100.f, 0.f));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));
	if (SphereVisualAsset.Succeeded())
	{
		meshSphere->SetStaticMesh(SphereVisualAsset.Object);
	}
}


// Called when the game starts
void URevolutionSceneComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	//SetWorldLocation(FVector(0.f, 50.f, 0.f));
}


// Called every frame
void URevolutionSceneComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	FRotator rotation = GetComponentRotation();
	rotation.Yaw += DeltaTime * 50.f;
	SetWorldRotation(rotation);
}

