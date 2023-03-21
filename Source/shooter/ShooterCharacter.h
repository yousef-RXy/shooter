// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

UCLASS()
class SHOOTER_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	/*camera boom positionig the camera behind the character*/
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;
	/*camera that follow the character*/
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
public:
	/*returns CameraBoom SubObject */
	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	/*returns FollowCamera SubObject */
	FORCEINLINE UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};
