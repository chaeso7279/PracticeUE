// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CameraSturcts.generated.h"

/**
 * 
 */
class QUICKSTART_API CameraSturcts
{
public:
	CameraSturcts();
	~CameraSturcts();
};

USTRUCT(Atomic)
struct FCameraStruct
{
	GENERATED_USTRUCT_BODY()
	
public:
	UPROPERTY(EditAnywhere)
	AActor* Camera;
	UPROPERTY(EditAnywhere)
	float timeChangeCamera;
	UPROPERTY(EditAnywhere)
	float timeSmoothBlend;
};
