// Fill out your copyright notice in the Description page of Project Settings.


#include "MetaHumanWidget.h"

void UMetaHumanWidget::Open() {

	GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeGameAndUI());

	GetWorld()->GetFirstPlayerController()->SetShowMouseCursor(true);

	AddToViewport();

	Button0->OnClicked.AddDynamic(this, &ThisClass::OnButton0Clicked);
}

void UMetaHumanWidget::OnButton0Clicked() {
	UE_LOG(LogTemp, Warning, TEXT("OnButton0Clicked"));

	Button0DDelegate.ExecuteIfBound();
}