#include "ActorVisionChecker.h"

// Sets default values
AActorVisionChecker::AActorVisionChecker()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called every frame
void AActorVisionChecker::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

/**
 * @description Checks whether the target actor is within the field of view and calculates the angle between forward vector and target direction.
 * @author Mateusz Chryc
 */
void AActorVisionChecker::AVisionCheck()
{
    if (!OtherObject || !GEngine) return;

    // Direction from this actor to target actor (normalized vector)
    FVector DirTowardsOtherObject = (OtherObject->GetActorLocation() - GetActorLocation()).GetSafeNormal();

    // Dot product between forward vector and direction to target
    float DotProduct = FVector::DotProduct(DirTowardsOtherObject, GetActorForwardVector());

    // Clamp to avoid numerical errors in Acos
    DotProduct = FMath::Clamp(DotProduct, -1.f, 1.f);

    // Convert dot product to angle in degrees
    Angle = FMath::RadiansToDegrees(FMath::Acos(DotProduct));

    if (DotProduct > 0.1f)
    {
        GEngine->AddOnScreenDebugMessage(
            -1, 1.0f, FColor::Green,
            FString::Printf(TEXT("Can see object! Angle: %.2f"), Angle)
        );
    }
    else
    {
        GEngine->AddOnScreenDebugMessage(
            -1, 1.0f, FColor::Red,
            FString::Printf(TEXT("Can't see object! Angle: %.2f"), Angle)
        );
    }
}