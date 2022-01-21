// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyItem.h"
#include "GameFramework/Actor.h"
#include "WeaponRifleBase.generated.h"


USTRUCT(BlueprintType)
struct FstructRifleSpreadInfo
{
	GENERATED_BODY()
public:
	FstructRifleSpreadInfo()
	{
		InitialAccuracy = 0.01;
		MaxAccuracy = 0.1;
		IncreasingSpeed = 7;
		IncreasingPower = 3.0;

	}
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float		InitialAccuracy;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float		MaxAccuracy;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int		IncreasingSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float		IncreasingPower;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float		SpredDecayTime;

};

USTRUCT(BlueprintType)
struct FstructRifleInfo
{
	GENERATED_BODY()
public:
	FstructRifleInfo()
	{
		FireInterval = 0.2;
	}
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float		FireInterval;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FstructRifleSpreadInfo	SpreadInfoDuck;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FstructRifleSpreadInfo	SpreadInfoSteady;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FstructRifleSpreadInfo	SpreadInfoMove;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FstructRifleSpreadInfo	SpreadInfoFallen;
};

UCLASS()
class MOBILETOPVIEW_API AWeaponRifleBase : public AMyItem
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeaponRifleBase();
	UFUNCTION(BlueprintCallable, Category = "Game Play")
		void	SetWeaponProperty(FstructRifleInfo pProperty);
	UFUNCTION(BlueprintCallable, Category = "Game Play")
		FstructRifleInfo&	GetWeaponProperty();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FstructRifleInfo	RifleProperty;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
