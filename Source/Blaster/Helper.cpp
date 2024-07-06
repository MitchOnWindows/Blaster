#include "Helper.h"

void Helper::Debug(FString text)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			5.f,
			FColor::Red,
			text
		);
	}
}
