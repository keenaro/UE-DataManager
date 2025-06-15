#include "DataManagerSubsystem.h"

void UDataManagerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	if(ensureAlwaysMsgf(LookupAssetPath.IsValid(), TEXT("LookupAssetPath should be declared inside Engine.ini otherwise the DataManager will not function.")))
	{
		LookupAsset = Cast<UDataManagerLookupAsset>(LookupAssetPath.TryLoad());
		ensure(LookupAsset);
	}
}