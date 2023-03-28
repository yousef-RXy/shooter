// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "ShooterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTER_API UShooterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	public:
		UFUNCTION(BlueprintCallable)
		void UpdateAnimationProperties(float DeltaTime);
		virtual void NativeInitializeAnimation() override;

	private:
		UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, category = Movement, meta = (AllowPrivateAccess = "true"))
		class AShooterCharacter* ShooterCharacter;

		UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, category = Movement, meta = (AllowPrivateAccess = "true"))
		float Speed;

		UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, category = Movement, meta = (AllowPrivateAccess = "true"))
		bool  bIsInAir;
		
		UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, category = Movement, meta = (AllowPrivateAccess = "true"))
		bool  bIsAccelerating;

		UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = Movement, meta = (AllowPrivateAccess = "true"))
		float MovementOffsetYaw;
};
