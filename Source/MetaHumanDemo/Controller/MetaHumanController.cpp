// Fill out your copyright notice in the Description page of Project Settings.


#include "MetaHumanController.h"

AMetaHumanController::AMetaHumanController() {

	Tool = CreateDefaultSubobject<UTool>(TEXT("Tool"));

}

void AMetaHumanController::BeginPlay() {
	Super::BeginPlay();

	MetaHumanWidget = Tool->GetUI<UMetaHumanWidget>("/Game/Blueprints/WBP_MetaHumanWidget.WBP_MetaHumanWidget_C");

	MetaHumanWidget->Button0DDelegate.BindUFunction(this, FName("TestFunc"));

	MetaHumanWidget->Open();
}

void AMetaHumanController::TestFunc_Implementation() {

	UE_LOG(LogTemp, Warning, TEXT("TestFunc_Implementation"));
}