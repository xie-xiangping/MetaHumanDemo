// Copyright Epic Games, Inc. All Rights Reserved.


#include "MetaHumanDemoGameModeBase.h"

AMetaHumanDemoGameModeBase::AMetaHumanDemoGameModeBase() {

	//绑定角色
	DefaultPawnClass = AMetaHumanCharacter::StaticClass();

	//绑定控制器
	PlayerControllerClass = ConstructorHelpers::FClassFinder<APlayerController>(TEXT("/Game/Blueprints/BP_MetaHumanController")).Class;
	//PlayerControllerClass = AMetaHumanController::StaticClass();
}