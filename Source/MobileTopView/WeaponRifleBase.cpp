// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponRifleBase.h"

// Sets default values
AWeaponRifleBase::AWeaponRifleBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWeaponRifleBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeaponRifleBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWeaponRifleBase::SetWeaponProperty(FstructRifleInfo pProperty)
{
	GEngine->AddOnScreenDebugMessage(-1, 22.f, FColor::Red, TEXT("AWeaponRifleBase::SetWeaponProperty"));
	RifleProperty = pProperty;
}

FstructRifleInfo& AWeaponRifleBase::GetWeaponProperty()
{
	return	RifleProperty;
}