// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "DataManagerLookupAsset.generated.h"

UCLASS(BlueprintType)
class DATAMANAGER_API UDataManagerLookupAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:
	template<typename TRowStruct>
	const TRowStruct* GetData(const FGameplayTag& DataCategory, const FGameplayTag& DataRow) const
	{
		auto* FoundCategory = DataLookup.Find(DataCategory);
		if(FoundCategory == nullptr)
		{
			return nullptr;
		}

		auto* CategoryDataTable = Cast<UDataTable>(FoundCategory->LoadSynchronous());
		if(!IsValid(CategoryDataTable))
		{
			return nullptr;
		}

		return CategoryDataTable->FindRow<TRowStruct>(DataRow.GetTagName(), TEXT("DataManager"), false);
	}

private:
	UPROPERTY(EditAnywhere)
	TMap<FGameplayTag, TSoftObjectPtr<UDataTable>> DataLookup;
};