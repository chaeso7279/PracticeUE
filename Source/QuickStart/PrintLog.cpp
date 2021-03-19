// Fill out your copyright notice in the Description page of Project Settings.


#include "PrintLog.h"
#include <Kismet/KismetSystemLibrary.h>

// Sets default values
APrintLog::APrintLog()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APrintLog::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APrintLog::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/* 매개변수 설명 
		첫번째인자: 앞에서 띄운 로그를 지울 지(-1 외의 값) or 다음 줄로 밀어내고 띄울지(-1)
		두번째인자: 로그가 화면에 남아있는 시간
		세번째인자: 로그 색상
		네번째인자: 출력할 내용
	*/
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("C++ Log Print(Only Viewport)")); // 뷰포트에만 출력, 로그 패널에는 출력 X

	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("C++ Log Print(Pannel, Viewport)"), true, true, FLinearColor::Green, 2.f);
}

