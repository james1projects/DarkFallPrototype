// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleUnit.h"

// Sets default values
ABattleUnit::ABattleUnit()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABattleUnit::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABattleUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABattleUnit::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABattleUnit::PerformAttack()
{
    if (!bCanAttack)
        return;

    // Trigger your animation or logic here
    UE_LOG(LogTemp, Warning, TEXT("Attacking!"));

    bCanAttack = false;

    // Start timer to re-enable attack
    GetWorld()->GetTimerManager().SetTimer(
        ReloadTimerHandle,
        this,
        &ABattleUnit::ResetAttack,
        ReloadTimer,
        false
    );
}

void ABattleUnit::ResetAttack()
{
    bCanAttack = true;
    UE_LOG(LogTemp, Warning, TEXT("Attack ready again"));
}
