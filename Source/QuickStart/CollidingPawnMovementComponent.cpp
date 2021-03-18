// Fill out your copyright notice in the Description page of Project Settings.


#include "CollidingPawnMovementComponent.h"

void UCollidingPawnMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	/*
		PawnOwner: 이 컴포넌트를 소유하고 있는 폰
		UpdatedComponent: UMovementComponent에 속한 변수, 이 무브먼트 컴포넌트가 이동시키고 업데이트 해야할 컴포넌트
		ShouldSkipUpdate: 이동된 컴포넌트가 이동할 수 없거나, 렌더링 되지 않은 경우인지 판별해줌 
	*/
	if (!PawnOwner || !UpdatedComponent || ShouldSkipUpdate(DeltaTime)) // => 즉, 이동가능한 상태인지 여부
		return;

	/*
		ConsumeInputVector(): 입력된 이동 벡터를 가져옴
		SafeMoveUpdatedComponent(): UE 피직스를 이용 -> 장애물을 피해 pawn 무브먼트 컴포넌트를 이동시켜줌
	*/
	FVector DesiredMovementThisFrame = ConsumeInputVector().GetClampedToMaxSize(1.f) * DeltaTime * 150.f;
	if (!DesiredMovementThisFrame.IsNearlyZero())
	{
		FHitResult Hit;
		SafeMoveUpdatedComponent(DesiredMovementThisFrame, UpdatedComponent->GetComponentRotation(), true, Hit);
		
		if (Hit.IsValidBlockingHit()) // 충돌이 발생했을 경우
		{
			// 충돌체의 표면을 타고 미끄러지며 이동하도록 함
			SlideAlongSurface(DesiredMovementThisFrame, 1.f - Hit.Time, Hit.Normal, Hit);
		}
	}
}