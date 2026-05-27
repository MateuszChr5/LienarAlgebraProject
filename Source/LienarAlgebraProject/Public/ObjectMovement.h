#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "ObjectMovement.generated.h"

UCLASS()
class LIENARALGEBRAPROJECT_API AObjectMovement : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AObjectMovement();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
