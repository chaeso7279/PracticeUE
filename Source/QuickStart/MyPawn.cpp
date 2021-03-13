// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include <Engine/Classes/Camera/CameraComponent.h>

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// ������ ���۵Ǹ� �ڵ����� �÷��̾��� �Է��� ����ǵ�����
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));

	UCameraComponent* ourCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("OurCamera"));
	ourCamera->SetupAttachment(RootComponent);
	
	// RootComponent�� ��������� ��ġ �� ȸ�� ����
	ourCamera->SetRelativeLocation(FVector(-250.f, 0.f, 250.f));
	ourCamera->SetRelativeRotation(FRotator(-45.f, 0.f, 0.f));

	ourVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));
	ourVisibleComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

