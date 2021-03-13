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
	Atomic: �ش� ����ü�� �׻� �ϳ��� ������ ����ȭ ��
			������ â���� ����ü�� ǥ�õǰ�, ���������ϵ��� �Ϸ��� Atomic�� ����ϸ� �� (Atomic / EditAnywhere)�� ����
			����ü�� ������ â���� ǥ�õ��� �ʰ�, �ڵ� or ���������� ���Ǳ� ���ϸ� Atomic �������� (BlueprintType / BlueprintReadWrite)�� ����
*/
USTRUCT(Atomic, BlueprintType)
struct FCustomStruct
{
	GENERATED_USTRUCT_BODY()
public: 
	/* ������ ��� ��, �躹 ���� */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AActor* actor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 i;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float f;
};