// Fill out your copyright notice in the Description page of Project Settings.


#include "MyItem.h"

// Sets default values
AMyItem::AMyItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
FStructMyItemInfo& AMyItem::GetMyItemInfo()
{
	return MyItemInfo;
}
/*
void AMyItem::TestItemInfo()
{
	GEngine->AddOnScreenDebugMessage(-1, 22.f, FColor::Blue, FString("AMyItem::TestItemInfo"));
}
*/
void AMyItem::TestItemInfo_Implementation(int nID)
{
	GEngine->AddOnScreenDebugMessage(-1, 22.f, FColor::Red, TEXT("AMyItem::TestItemInfo"));
	MySerialNumber = nID + 100;
}

void AMyItem::SetItemInfo_Implementation(FStructMyItemInfo ItemInfo)
{
	GEngine->AddOnScreenDebugMessage(-1, 22.f, FColor::Red, TEXT("AMyItem::SetItemInfo"));
	MyItemInfo = ItemInfo;
}

