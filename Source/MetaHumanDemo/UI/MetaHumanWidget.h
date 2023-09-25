// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Components/Button.h"
#include "MetaHumanDemo/Tools/Tool.h"

#include "MetaHumanWidget.generated.h"

/**
 * 
 */
UCLASS()
class METAHUMANDEMO_API UMetaHumanWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	void Open();

	Delegate00 Button0DDelegate;

protected:

	UFUNCTION()
	virtual void OnButton0Clicked();

	UPROPERTY(meta = (BindWidget))
	UButton* Button0;
};
