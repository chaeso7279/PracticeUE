// Fill out your copyright notice in the Description page of Project Settings.


#include "CollidingPawn.h"
#include <Engine/Classes/Components/SphereComponent.h>
#include <Engine/Classes/Particles/ParticleSystemComponent.h>
#include <Engine/Classes/GameFramework/SpringArmComponent.h>
#include <Engine/Classes/Camera/CameraComponent.h>
#include "CollidingPawnMovementComponent.h"

// Sets default values
ACollidingPawn::ACollidingPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// USphereComponent: 구 형태의 충돌체 / 눈에 보이지 X
	USphereComponent* collSphere = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	RootComponent = collSphere;
	collSphere->InitSphereRadius(40.f);
	collSphere->SetCollisionProfileName(TEXT("Pawn")); // 이 컴포넌트가 가진 콜리젼이 어떤 콜리젼과의 충돌을 감지할 것인지 설정 

	UStaticMeshComponent* meshSphere = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshSphere"));
	meshSphere->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));
	if (SphereVisualAsset.Succeeded())
	{
		meshSphere->SetStaticMesh(SphereVisualAsset.Object);
		meshSphere->SetRelativeLocation(FVector(0.f, 0.f, -40.f));
		meshSphere->SetWorldScale3D(FVector(0.8f));
	}

	ourParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("OurParticleSystem"));
	ourParticleSystem->SetupAttachment(RootComponent);
	ourParticleSystem->bAutoActivate = false; // 자동실행 X
	ourParticleSystem->SetRelativeLocation(FVector(-20.f, 0.f, 20.f));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleAsset(TEXT("/Game/StarterContent/Particles/P_Fire.P_Fire"));
	if (ParticleAsset.Succeeded())
		ourParticleSystem->SetTemplate(ParticleAsset.Object);

	// USpringArmComponent: 캐릭터를 느리게 따라가는 카메라 or 캐릭터가 벽을 뚫지 않게해주는 기능 제공
	USpringArmComponent* springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraAttachmentArm"));
	springArm->SetupAttachment(RootComponent);
	springArm->SetRelativeRotation(FRotator(-45.f, 0.f, 0.f));
	springArm->TargetArmLength = 400.f;
	springArm->bEnableCameraLag = true;
	springArm->CameraLagSpeed = 3.f;

	// SpringArm에 붙일 카메라 생성
	UCameraComponent* cameraCmp = CreateDefaultSubobject<UCameraComponent>(TEXT("ActualCamera"));
	cameraCmp->SetupAttachment(springArm, USpringArmComponent::SocketName); // SpringArm에 내장된 소켓에 부착

	ourMovementCmp = CreateDefaultSubobject<UCollidingPawnMovementComponent>(TEXT("OurMovementComponent"));
	ourMovementCmp->UpdatedComponent = RootComponent; // MoveCmp가 RootCmp를 따라 업데이트 되도록 설정


	AutoPossessPlayer = EAutoReceiveInput::Player0; // 기본 플레이어의 입력받음
}

// Called when the game starts or when spawned
void ACollidingPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACollidingPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACollidingPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// 입력 매핑 바인딩
	InputComponent->BindAction("ParticleToggle", IE_Pressed, this, &ACollidingPawn::ParticleToggle);

	InputComponent->BindAxis("MoveForward", this, &ACollidingPawn::MoveFoward);
	InputComponent->BindAxis("MoveRight", this, &ACollidingPawn::MoveRight);
	InputComponent->BindAxis("Turn", this, &ACollidingPawn::Turn);
}

UPawnMovementComponent * ACollidingPawn::GetMovementComponent() const
{
	return ourMovementCmp;
}

void ACollidingPawn::MoveFoward(float AxisValue)
{
	if (ourMovementCmp && ourMovementCmp->UpdatedComponent == RootComponent)
		ourMovementCmp->AddInputVector(AxisValue * GetActorForwardVector());
}

void ACollidingPawn::MoveRight(float AxisValue)
{
	if (ourMovementCmp && ourMovementCmp->UpdatedComponent == RootComponent)
		ourMovementCmp->AddInputVector(AxisValue * GetActorRightVector());
}

void ACollidingPawn::Turn(float AxisValue)
{
	FRotator rotation = GetActorRotation();
	rotation.Yaw += AxisValue;
	SetActorRotation(rotation);
}

void ACollidingPawn::ParticleToggle()
{
	if (ourParticleSystem && ourParticleSystem->Template)
		ourParticleSystem->ToggleActive();
}