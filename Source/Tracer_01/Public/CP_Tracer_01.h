#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CP_Tracer_01.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TRACER_01_API UCP_Tracer_01 : public UActorComponent{
	GENERATED_BODY()

public:	

	UCP_Tracer_01();

protected:

	virtual void BeginPlay() override;

public:	

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UPROPERTY(EditAnywhere, Category = "Collision")
		TEnumAsByte<ECollisionChannel> TraceChannelProperty = ECC_Pawn;


	UFUNCTION(BlueprintCallable, Category = "Actor_BP Functions")
		bool Trace_typeA(FVector start, FVector end);
	// check extra 
	UFUNCTION(BlueprintPure, Category = "Actor_BP Functions")
		bool Trace_typeB(FVector start, FVector end);

	FHitResult Hit;
	FVector TraceStart = FVector::ZeroVector;
	FVector TraceEnd = FVector::ZeroVector;

	FCollisionQueryParams QueryParams;
	
};
