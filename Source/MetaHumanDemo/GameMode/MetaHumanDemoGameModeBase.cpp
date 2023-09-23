// Copyright Epic Games, Inc. All Rights Reserved.


#include "MetaHumanDemoGameModeBase.h"

AMetaHumanDemoGameModeBase::AMetaHumanDemoGameModeBase() {

	//�󶨽�ɫ
	DefaultPawnClass = AMetaHumanCharacter::StaticClass();

	//�󶨿�����
	PlayerControllerClass = ConstructorHelpers::FClassFinder<APlayerController>(TEXT("/Game/Blueprints/BP_MetaHumanController")).Class;
	//PlayerControllerClass = AMetaHumanController::StaticClass();
}