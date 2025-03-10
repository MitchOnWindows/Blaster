#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "BlasterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class BLASTER_API UBlasterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override; // like begin play
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

private:
	UPROPERTY(BlueprintReadOnly, Category=Character, meta = (AllowPrivateAccess="true"));
	class ABlasterCharacter* BlasterCharacter;

	UPROPERTY(BlueprintReadOnly, Category=Movement, meta = (AllowPrivateAccess="true"));
	float Speed;

	UPROPERTY(BlueprintReadOnly, Category=Movement, meta = (AllowPrivateAccess="true"));
	bool bIsInAir;

	UPROPERTY(BlueprintReadOnly, Category=Movement, meta = (AllowPrivateAccess="true"));
	bool bIsAccelerating;

	UPROPERTY(BlueprintReadOnly, Category=Movement, meta = (AllowPrivateAccess="true"));
	bool bWeaponEquipped;

	UPROPERTY(BlueprintReadOnly, Category=Movement, meta = (AllowPrivateAccess="true"));
	bool bIsCrouched;

	UPROPERTY(BlueprintReadOnly, Category=Movement, meta = (AllowPrivateAccess="true"));
	bool bAiming;

	UPROPERTY(BlueprintReadOnly, Category=Movement, meta = (AllowPrivateAccess="true"));
	float YawOffset;

	UPROPERTY(BlueprintReadOnly, Category=Movement, meta = (AllowPrivateAccess="true"));
	float Lean;

	FRotator CharacterRotationLastFrame;
	FRotator CharacterRotation;
	FRotator DeltaRotation;
};
