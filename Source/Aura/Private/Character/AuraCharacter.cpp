// Copyright Egemen Ton


#include "Character/AuraCharacter.h"


#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"

 AAuraCharacter::AAuraCharacter()
{
 	GetCharacterMovement()->bOrientRotationToMovement = true;
 	GetCharacterMovement()->RotationRate = FRotator(0.f,400.f,0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
 	GetCharacterMovement()->bSnapToPlaneAtStart = true;

 	bUseControllerRotationPitch = false;
 	bUseControllerRotationRoll = false;
 	bUseControllerRotationYaw = false;
 	
	CameraArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraArm->SetupAttachment(GetCapsuleComponent());
	CameraArm->TargetArmLength = 750.f;
 	CameraArm->SetRelativeRotation(FRotator(-45.f, 0.f, 0.f));
 	CameraArm->bEnableCameraLag = true;
 	CameraArm->bInheritYaw = false;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraArm, USpringArmComponent::SocketName);
}

