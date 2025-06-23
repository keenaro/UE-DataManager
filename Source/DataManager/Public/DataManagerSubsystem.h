#pragma once

#include "CoreMinimal.h"
#include "DataManagerLookupAsset.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "DataManagerSubsystem.generated.h"

UCLASS(config=Game)
class DATAMANAGER_API UDataManagerSubsystem : public UEngineSubsystem
{
	GENERATED_BODY()

public:
	template<typename TRowStruct>
	static const TRowStruct* GetData(const FGameplayTag& DataCategory, const FGameplayTag& DataRow)
	{
		const auto* DataManager = GEngine ? GEngine->GetEngineSubsystem<UDataManagerSubsystem>() : nullptr;
		if(!DataManager)
		{
			return nullptr;
		}
		return DataManager->Internal_GetData<TRowStruct>(DataCategory, DataRow);
	}

protected:
	template<typename TRowStruct>
	const TRowStruct* Internal_GetData(const FGameplayTag& DataCategory, const FGameplayTag& DataRow) const
	{
		return LookupAsset->GetData<TRowStruct>(DataCategory, DataRow);
	}
	
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	
private:
	UPROPERTY()
	TObjectPtr<UDataManagerLookupAsset> LookupAsset = nullptr;

	UPROPERTY(config)
	FSoftObjectPath LookupAssetPath;
};
