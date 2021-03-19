// Copyright Epic Games, Inc. All Rights Reserved.


#include "QuickStartGameModeBase.h"
#include <Blueprint/UserWidget.h>

void AQuickStartGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	ChangeMenuWidget(StartingWidgetClass);
}

void AQuickStartGameModeBase::ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass)
{
	if (CurrentWidget != nullptr)
	{
		// 현재 위젯이 있다면 뷰포트에서 제거
		CurrentWidget->RemoveFromViewport(); 
		CurrentWidget = nullptr;
	}

	if (NewWidgetClass != nullptr)
	{
		// 인자로 들어온 위젯이 유효하다면 현재 위젯으로 만든 후,
		CurrentWidget = CreateWidget(GetWorld(), NewWidgetClass);
		if (CurrentWidget)
			CurrentWidget->AddToViewport(); // 뷰포트에 추가
	}
}