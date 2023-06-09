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
	//called for forwards/backwards input
	void MoveForward(float Value);
	//called for side to side input
	void MoveRight(float Value);

	/*
	*	called via input to turn at given rate
	*		@param rate this is a normalized rate, i.e. 1.0 means100% of desired turn rate
	*/
	void TurnAtRate(float Rate);
	
	/*
	* called via input to look up/down at given rate
	* @param rate this is a normalized rate, i.e. 1.0 means100% of desired turn rate
	*/
	void LookUpAtRate(float Rate);

	/*
	* called when the fire button pressed
	*/
	void FireWeapon();

	bool GetBeamEndLocation(const FVector& MuzzelSocketLocation, FVector& OutBeamLocation);


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	/*camera boom positioning the camera behind the character*/
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;
	/*camera that follow the character*/
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	//base turn rate and deg/sec. Other scaling may affect final turn rate
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly,category=camera, meta = (AllowPrivateAccess = "true"))
	float BaseTurnRate;

	//base look up/down rate, in deg/sec. Other scaling may affect final turn rate
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, category = camera, meta = (AllowPrivateAccess = "true"))
	float BaseLookUpRate;


	//sound Spawned When fire
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = Compat, meta = (AllowPrivateAccess = "true"))
	class USoundCue* FireSound;
	
	//Flash Spawned at barrelSocket
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = Compat, meta = (AllowPrivateAccess = "true"))
	class UParticleSystem* MuzzelFlash;

	//montage for fire the weapon
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = Compat, meta = (AllowPrivateAccess = "true"))
	class UAnimMontage* HipFireMontage;

	//Particles Spawned upon bullet impact
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = Compat, meta = (AllowPrivateAccess = "true"))
	UParticleSystem* ImpactParticles;

	//Smoke Trail For Bullets
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = Compat, meta = (AllowPrivateAccess = "true"))
	UParticleSystem* BeamParticles;

public:
	/*returns CameraBoom SubObject */
	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	/*returns FollowCamera SubObject */
	FORCEINLINE UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};
