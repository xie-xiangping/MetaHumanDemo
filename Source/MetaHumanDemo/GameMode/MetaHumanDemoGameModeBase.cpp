// Copyright Epic Games, Inc. All Rights Reserved.


#include "MetaHumanDemoGameModeBase.h"

AMetaHumanDemoGameModeBase::AMetaHumanDemoGameModeBase() {

	//�󶨽�ɫ
	DefaultPawnClass = AMetaHumanCharacter::StaticClass();

	//�󶨿�����
	PlayerControllerClass = AMetaHumanController::StaticClass();

}