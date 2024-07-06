#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "BlasterCharacter.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class BLASTER_API ABlasterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABlasterCharacter();
    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void Jump() override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostInitializeComponents() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category="EnhancedInput")
	UInputMappingContext* InputMapping;
	
	UPROPERTY(EditAnywhere, Category="EnhancedInput")
	UInputAction* MovementAction;

	UPROPERTY(EditAnywhere, Category="EnhancedInput")
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, Category="EnhancedInput")
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, Category="EnhancedInput")
	UInputAction* EquipAction;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void EquipButtonPressed();
	
private:
	UPROPERTY(VisibleAnywhere, Category = Camera)
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, Category = Camera)
	class UCameraComponent* FollowCamera;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess="true"))
	class UWidgetComponent* OverheadWidget;

	UPROPERTY(ReplicatedUsing = OnRep_OverlappingWeapon)
	class AWeapon* OverlappingWeapon;

	UFUNCTION()
	void OnRep_OverlappingWeapon(AWeapon* LastWeapon);

	UPROPERTY(VisibleAnywhere)
	class UCombatComponent* Combat;

	UFUNCTION(Server, Reliable)
	void ServerEquipButtonPress();
	
public:	
	void SetOverlappingWeapon(AWeapon* Weapon);

};
