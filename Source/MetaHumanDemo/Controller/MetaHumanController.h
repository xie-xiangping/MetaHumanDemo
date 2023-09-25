// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "MetaHumanDemo/Tools/Tool.h"
#include "MetaHumanDemo/UI/MetaHumanWidget.h"

#include "MetaHumanController.generated.h"

/**
 * 
 */
UCLASS()
class METAHUMANDEMO_API AMetaHumanController : public APlayerController
{
	GENERATED_BODY()

public:

	AMetaHumanController();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool testFlag = true;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void TestFunc();
protected:

	UPROPERTY(BlueprintReadWrite)
	UMetaHumanWidget* MetaHumanWidget;

private:

	UTool* Tool;
};
