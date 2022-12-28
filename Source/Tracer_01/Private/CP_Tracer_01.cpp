#include "CP_Tracer_01.h"

UCP_Tracer_01::UCP_Tracer_01(){
	PrimaryComponentTick.bCanEverTick = true;

}

void UCP_Tracer_01::BeginPlay(){
	Super::BeginPlay();
}


void UCP_Tracer_01::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction){
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

bool UCP_Tracer_01::Trace_typeA(FVector start, FVector end){
	
	GetWorld()->LineTraceSingleByChannel(Hit, start, end, TraceChannelProperty, QueryParams);
	DrawDebugLine(GetWorld(), start, end, Hit.bBlockingHit ? FColor::Blue : FColor::Red, false, 5.0f, 0, 10.0f);
	UE_LOG(LogTemp, Log, TEXT(">> KTX --- Trace_typeA : %s to %s"), *start.ToCompactString(), *end.ToCompactString());

	if (Hit.bBlockingHit && IsValid(Hit.GetActor())){
		UE_LOG(LogTemp, Log, TEXT(">> KTX --- Trace_typeA --  hit actor: %s"), *Hit.GetActor()->GetName());
		return true;
	}
	//else {
	//	UE_LOG(LogTemp, Log, TEXT("No Actors were hit"));
	//}


	return false;
}

bool UCP_Tracer_01::Trace_typeB(FVector start, FVector end){
	GetWorld()->LineTraceSingleByChannel(Hit, start, end, TraceChannelProperty, QueryParams);
	DrawDebugLine(GetWorld(), start, end, Hit.bBlockingHit ? FColor::Blue : FColor::Red, false, 5.0f, 0, 10.0f);
	UE_LOG(LogTemp, Log, TEXT(">> KTX --- Trace_typeB : %s to %s"), *start.ToCompactString(), *end.ToCompactString());

	if (Hit.bBlockingHit && IsValid(Hit.GetActor())) {
		UE_LOG(LogTemp, Log, TEXT(">> KTX --- Trace_typeB -- hit actor: %s"), *Hit.GetActor()->GetName());
		return true;
	}

	return false;
}

