// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BattleUnit.generated.h"

UCLASS()
class DARKFALLPROTOTYPE_API ABattleUnit : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABattleUnit();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void ResetAttack();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// In your Character or Actor header file
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float ReloadTimer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	bool bCanAttack = true;

	void PerformAttack();

	FTimerHandle ReloadTimerHandle;
};
