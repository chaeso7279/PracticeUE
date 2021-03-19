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

	/* �Ű����� ���� 
		ù��°����: �տ��� ��� �α׸� ���� ��(-1 ���� ��) or ���� �ٷ� �о�� �����(-1)
		�ι�°����: �αװ� ȭ�鿡 �����ִ� �ð�
		����°����: �α� ����
		�׹�°����: ����� ����
	*/
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("C++ Log Print(Only Viewport)")); // ����Ʈ���� ���, �α� �гο��� ��� X

	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("C++ Log Print(Pannel, Viewport)"), true, true, FLinearColor::Green, 2.f);
}

