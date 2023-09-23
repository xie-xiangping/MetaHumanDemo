// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "Blueprint/UserWidget.h"

#include "Tool.generated.h"

//无返回值，无函数参数
DECLARE_DELEGATE(DTDelegate);

/**
 * 
 */
UCLASS()
class METAHUMANDEMO_API UTool : public UObject
{
	GENERATED_BODY()

public:

	template <typename T>
	T* GetUI(FString Path) {
		UClass* Widget = LoadClass<UUserWidget>(NULL, *Path);
		return CreateWidget<T>(GetWorld(), Widget);
	}
};