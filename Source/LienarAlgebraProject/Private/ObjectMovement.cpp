#include "ObjectMovement.h"

// Sets default values
AObjectMovement::AObjectMovement()
{
 	// Tick must to be active, because our movement ussing this func.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AObjectMovement::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AObjectMovement::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); //It's necesary to work same on every pc independently of fps

	FVector Forward = GetActorForwardVector(); //This func get actor's forward vector
	float Speed = 300.0f; //Create new variable float Speed and set it to 300

	FVector NewLocation = GetActorLocation() + (Forward * Speed * DeltaTime); //Get location of actor and adding to it vector
	
	SetActorLocation(NewLocation); //Every tick changing actor possition
}


