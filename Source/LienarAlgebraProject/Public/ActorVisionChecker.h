#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorVisionChecker.generated.h"

UCLASS()
class LIENARALGEBRAPROJECT_API AActorVisionChecker : public AActor
{
    GENERATED_BODY()

public:
    AActorVisionChecker();

    // Target actor
    UPROPERTY(EditAnywhere, Category = "Vision")
    AActor* OtherObject;

    // Angle between forward vector and target direction
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Vision")
    float Angle;

    virtual void Tick(float DeltaTime) override;

private:
    // Declaring a function
    UFUNCTION(BlueprintCallable, Category = "Vision")
    void AVisionCheck();
};