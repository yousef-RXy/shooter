// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAnimInstance.h"
#include "ShooterCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"


void UShooterAnimInstance::UpdateAnimationProperties(float DeltaTime)
{
	if (ShooterCharacter == nullptr) {
		ShooterCharacter = Cast<AShooterCharacter>(TryGetPawnOwner());
	}
	if (ShooterCharacter) {
		//get the later speed of the characters
		FVector Velocity{ ShooterCharacter->GetVelocity() };
		Velocity.Z = 0;
		Speed = Velocity.Size();

		// is in air
		bIsInAir = ShooterCharacter->GetCharacterMovement()->IsFalling();

		//is accelerating
		if(ShooterCharacter->GetCharacterMovement()->GetCurrentAcceleration().Size()>0.f){
			bIsAccelerating = true;
		}
		else {
			bIsAccelerating = false;
		}
	}
}

void UShooterAnimInstance::NativeInitializeAnimation()
{
	ShooterCharacter = Cast<AShooterCharacter>(TryGetPawnOwner());
}
