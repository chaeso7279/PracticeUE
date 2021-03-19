// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CustomStructs.generated.h"

/**
 * 
 */
class QUICKSTART_API CustomStructs
{
public:
	CustomStructs();
	~CustomStructs();
};

/*
	Atomic: 해당 구조체가 항상 하나의 단위로 직렬화 됨
			디테일 창에서 구조체가 표시되고, 수정가능하도록 하려면 Atomic만 사용하면 됨 (Atomic / EditAnywhere)로 설정
			구조체가 디테일 창에서 표시되지 않고, 코드 or 블프에서만 사용되길 원하면 Atomic 빼버리기 (BlueprintType / BlueprintReadWrite)로 설정
*/
USTRUCT(Atomic, BlueprintType)
struct FCustomStruct
{
	GENERATED_USTRUCT_BODY()
public: 
	/* 포인터 멤버 깊복, 얕복 주의 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AActor* actor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 i;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float f;
};