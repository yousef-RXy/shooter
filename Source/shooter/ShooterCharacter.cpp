// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "camera/CameraComponent.h"


// Sets default values
AShooterCharacter::AShooterCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom-> SetupAttachment(RootComponent);
	CameraBoom-> TargetArmLength=300.f;//the camer follows at this distance behind the character
	CameraBoom-> bUsePawnControlRotation =true;//rotate the arm based on the controller
	//create the follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera -> SetupAttachment(CameraBoom, USpringArmComponent::SocketName);//Attach the camera to the end of the boom
	FollowCamera -> bUsePawnControlRotation = false;//camera doesn't rotate relative to arm

}

// Called when the game starts or when spawned
void AShooterCharacter::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Some warning message!"));
}

// Called every frame
void AShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

