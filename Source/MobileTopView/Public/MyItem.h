// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyItem.generated.h"

UENUM(BlueprintType)
enum class E_enumMyItemType : uint8 {
	E_WEAPON_RIFLE = 0		UMETA(DisplayName = "E_WEAPON_RIFLE"),
	E_WEAPON_PEOJECTILE = 1	UMETA(DisplayName = "E_WEAPON_PEOJECTILE"),
	E_WEAPON_MELEE = 2		UMETA(DisplayName = "E_WEAPON_MELEE"),
	E_COSTUME = 3			UMETA(DisplayName = "E_COSTUME")
};

UENUM(BlueprintType)
enum class E_enumMyItemSubType : uint8 {
	E_AR = 0			UMETA(DisplayName = "E_AR"),
	E_SMG = 1			UMETA(DisplayName = "E_SMG"),
	E_SR = 2			UMETA(DisplayName = "E_SR"),
	E_UPPER = 3			UMETA(DisplayName = "E_UPPER"),
	E_LOWER = 4			UMETA(DisplayName = "E_LOWER"),
	E_HAT = 5			UMETA(DisplayName = "E_HAT"),
	E_BOOTS = 6			UMETA(DisplayName = "E_BOOTS"),
};

USTRUCT(BlueprintType)
struct FStructMyItemInfo
{
	GENERATED_BODY()
public:
	FStructMyItemInfo()
	{
	}
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info Struct")
		int		ItemID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info Struct")
		FString	ItemName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info Struct")
		TSubclassOf<AActor>			ClassRef;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info Struct")
		E_enumMyItemType			ItemType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info Struct")
		E_enumMyItemSubType			ItemSubType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info Struct")
		FSoftObjectPath 			StaticMeshRef;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Info Struct")
		FSoftObjectPath 			SkeletalMeshRef;
};

UCLASS()
class MOBILETOPVIEW_API AMyItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyItem();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ItemInfo")
		void	TestItemInfo(int nID);
	virtual void	TestItemInfo_Implementation(int nID);
	UFUNCTION(BlueprintCallable, Category = "ItemInfo")
		FStructMyItemInfo& GetMyItemInfo();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ItemInfo")
		void	SetItemInfo(FStructMyItemInfo ItemInfo);
	virtual	void	SetItemInfo_Implementation(FStructMyItemInfo ItemInfo);
	UFUNCTION(BlueprintCallable, Category = "ItemInfo")
		int		GetSerialNumber() { return MySerialNumber; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	int		MySerialNumber;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	FStructMyItemInfo MyItemInfo;

};
