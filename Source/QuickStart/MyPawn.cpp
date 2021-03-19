// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include <Engine/Classes/Camera/CameraComponent.h>

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 게임이 시작되면 자동으로 플레이어의 입력이 연결되도록함
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));

	UCameraComponent* ourCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("OurCamera"));
	ourCamera->SetupAttachment(RootComponent);
	
	// RootComponent를 기반으로한 위치 및 회전 설정
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
	
	Growing(DeltaTime);
	Move(DeltaTime);
}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// 함수 - 입력 바인딩
	PlayerInputComponent->BindAction("Grow", IE_Pressed, this, &AMyPawn::StartGrowing);
	PlayerInputComponent->BindAction("Grow", IE_Released, this, &AMyPawn::StopGrowing);

	PlayerInputComponent->BindAxis("MoveX", this, &AMyPawn::MoveXAxis);
	PlayerInputComponent->BindAxis("MoveY", this, &AMyPawn::MoveYAxis);
}

void AMyPawn::MoveXAxis(float AxisValue)
{
	// Clamp 사용 이유: 입력 키가 두개 이상 지정되어 있을 때, 배로 입력이 들어오는 경우를 막기 위함
	curVelocity.X = FMath::Clamp(AxisValue, -1.f, 1.f) * 100.f;
}

void AMyPawn::MoveYAxis(float AxisValue)
{
	curVelocity.Y = FMath::Clamp(AxisValue, -1.f, 1.f) * 100.f;
}

void AMyPawn::Move(float DeltaTime)
{
	if (!curVelocity.IsZero())
	{
		inputTime += DeltaTime;

		float speed = (inputTime <= 1.f ? 1.f : inputTime * 3.f);
		
		FVector newLocation = GetActorLocation() + (curVelocity * DeltaTime * FMath::Clamp(speed, 1.f, 5.f));
		SetActorLocation(newLocation);
	}
	else
		inputTime = 0.f;
}

void AMyPawn::StartGrowing()
{
	bGrowing = true;
}

void AMyPawn::StopGrowing()
{
	bGrowing = false;
}

void AMyPawn::Growing(float DeltaTime)
{
	FVector curScale = ourVisibleComponent->GetComponentScale();
	if (bGrowing)
	{
		if (inputTime > 0.f && inputTime <= 0.5f) // 누른 직후일 경우
			curScale.Z = 2.f;
		else
			curScale.Z += DeltaTime;
	}
	else
		curScale.Z -= DeltaTime * 0.5f;

	curScale.Z = FMath::Clamp(curScale.Z, 1.f, 2.f);
	ourVisibleComponent->SetWorldScale3D(curScale);
}