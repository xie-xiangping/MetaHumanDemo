// Fill out your copyright notice in the Description page of Project Settings.


#include "MetaHumanCharacter.h"

// Sets default values
AMetaHumanCharacter::AMetaHumanCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//������������Ϊ0��ʹ�䲻������Ӱ��
	GetCharacterMovement()->GravityScale = 0.0f;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->bUsePawnControlRotation = true;

	//�����Ҫ�����ڵ��ɱ���,���ܵ����۳�
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent);
	CameraComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f)); // Position the camera
	CameraComponent->bUsePawnControlRotation = true;

	DefaultMappingContext = ConstructorHelpers::FObjectFinder<UInputMappingContext>(TEXT("/Game/Input/IMC_Default.IMC_Default")).Object;

	MouseWheelUPAction = ConstructorHelpers::FObjectFinder<UInputAction>(TEXT("/Game/Input/Actions/IA_MouseWheelUP.IA_MouseWheelUP")).Object;
	MouseWheelDownAction = ConstructorHelpers::FObjectFinder<UInputAction>(TEXT("/Game/Input/Actions/IA_MouseWheelDown.IA_MouseWheelDown")).Object;

	SpringArmComponent->TargetArmLength = -16.0f;
}

// Called when the game starts or when spawned
void AMetaHumanCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PlayerController = Cast<APlayerController>(Controller)) {
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer())) {
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

// Called every frame
void AMetaHumanCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (ArmLengthChange) {
		if (fabsf(SpringArmComponent->TargetArmLength - ArmLength) > 0.001f) {
			SpringArmComponent->TargetArmLength = FMath::FInterpTo(SpringArmComponent->TargetArmLength, ArmLength, DeltaTime, InterpSpeed);
		}
		else {
			ArmLengthChange = false;
		}
	}

	//GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Blue, FString::Printf(TEXT("%f"), SpringArmComponent->TargetArmLength));
}

// Called to bind functionality to input
void AMetaHumanCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent)) {
		EnhancedInputComponent->BindAction(MouseWheelUPAction, ETriggerEvent::Triggered, this, &ThisClass::MouseWheelUP);
		EnhancedInputComponent->BindAction(MouseWheelDownAction, ETriggerEvent::Triggered, this, &ThisClass::MouseWheelDown);
	}
}

void AMetaHumanCharacter::MouseWheelUP()
{
	ArmLengthChange = true;

	if (ArmLength > -71.9f) {
		ArmLength -= 8.0f;
	}
}

void AMetaHumanCharacter::MouseWheelDown()
{
	ArmLengthChange = true;

	if (ArmLength < -16.1f) {
		ArmLength += 8.0f;
	}
}