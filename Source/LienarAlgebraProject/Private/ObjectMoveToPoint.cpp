#include "ObjectMoveToPoint.h"

AObjectMoveToPoint::AObjectMoveToPoint()
{
	PrimaryActorTick.bCanEverTick = true;

}

/**
 * @description Moves this actor toward the target actor every tick using a normalized direction vector.
 * @author Mateusz Chryc
 */
void AObjectMoveToPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector MyPosition = GetActorLocation(); // Get the actor’s location.
	FVector OtherPosition = OtherActor->GetActorLocation(); // Get the actor to follow

	FVector MovementDir = (OtherPosition - MyPosition).GetSafeNormal(); // Calculating direction to other actor

	FVector NewPosition = MyPosition + MovementDir * Speed * DeltaTime; // Calculating velocity and position
	SetActorLocation(NewPosition); // Update actor location every tick
}

