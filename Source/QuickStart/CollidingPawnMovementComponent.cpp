// Fill out your copyright notice in the Description page of Project Settings.


#include "CollidingPawnMovementComponent.h"

void UCollidingPawnMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	/*
		PawnOwner: �� ������Ʈ�� �����ϰ� �ִ� ��
		UpdatedComponent: UMovementComponent�� ���� ����, �� �����Ʈ ������Ʈ�� �̵���Ű�� ������Ʈ �ؾ��� ������Ʈ
		ShouldSkipUpdate: �̵��� ������Ʈ�� �̵��� �� ���ų�, ������ ���� ���� ������� �Ǻ����� 
	*/
	if (!PawnOwner || !UpdatedComponent || ShouldSkipUpdate(DeltaTime)) // => ��, �̵������� �������� ����
		return;

	/*
		ConsumeInputVector(): �Էµ� �̵� ���͸� ������
		SafeMoveUpdatedComponent(): UE �������� �̿� -> ��ֹ��� ���� pawn �����Ʈ ������Ʈ�� �̵�������
	*/
	FVector DesiredMovementThisFrame = ConsumeInputVector().GetClampedToMaxSize(1.f) * DeltaTime * 150.f;
	if (!DesiredMovementThisFrame.IsNearlyZero())
	{
		FHitResult Hit;
		SafeMoveUpdatedComponent(DesiredMovementThisFrame, UpdatedComponent->GetComponentRotation(), true, Hit);
		
		if (Hit.IsValidBlockingHit()) // �浹�� �߻����� ���
		{
			// �浹ü�� ǥ���� Ÿ�� �̲������� �̵��ϵ��� ��
			SlideAlongSurface(DesiredMovementThisFrame, 1.f - Hit.Time, Hit.Normal, Hit);
		}
	}
}