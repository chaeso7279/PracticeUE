// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"

/*
	Pawn 클래스:
	플레이어 혹은 AI의 컨트롤러가 연결되어 제어받도록 하는 클래스
*/


UCLASS()
class QUICKSTART_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	/*
		USceneComponent: 트랜스폼 정보를 갖고 있음, 월드에 배치할 수 있는 다른 컴포넌트들의 부모클래스
						 매우 가볍기 때문에(충돌, 렌더링 지원X) 계층구조에서 더미로 사용하기 좋음
	*/
	UPROPERTY(EditAnywhere)
	USceneComponent* ourVisibleComponent;

};
