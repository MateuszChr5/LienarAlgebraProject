#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObjectMoveToPoint.generated.h"

UCLASS()
class LIENARALGEBRAPROJECT_API AObjectMoveToPoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObjectMoveToPoint();

	UPROPERTY(EditAnywhere) //Target actor that this actor will point toward and follow
	AActor* OtherActor;

	UPROPERTY(EditAnywhere) //Movement speed
	float Speed = 300.f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
