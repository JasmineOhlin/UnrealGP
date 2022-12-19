#pragma once

#include "ItemPDABase.h"
#include "InventoryStructs.generated.h"

USTRUCT(BlueprintType)
struct FItemStruct{
	GENERATED_BODY()

	FItemStruct(): ItemPDA(nullptr), Durability(0),Id(FGuid::NewGuid()) {}

	FItemStruct(UItemPDABase* ItemPDA) : ItemPDA(ItemPDA), Durability(100), Id(FGuid::NewGuid()) {}

	FItemStruct(UItemPDABase* ItemPDA, float Durability) : ItemPDA(ItemPDA), Durability(Durability), Id(FGuid::NewGuid()) {}

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UItemPDABase* ItemPDA;

	UPROPERTY(BlueprintReadWrite)
	float Durability;

	UPROPERTY(VisibleAnywhere)
	FGuid Id;

	bool operator ==(const FItemStruct& Other) const
	{
		return this -> Id == Other.Id && ItemPDA;
	}

	bool IsValid() const;
};
