// Fill out your copyright notice in the Description page of Project Settings.


#include "Mover.h"
#include "Math/UnrealMathUtility.h"

// Sets default values for this component's properties
UMover::UMover()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMover::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetOwner()->GetActorLocation();
	TargetLocation = StartLocation + MovingDistance;

}


// Called every frame
void UMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	

	if (Moved)
	{
		FVector CurrentLocation = GetOwner()->GetActorLocation();

		float Speed = FVector::Dist(StartLocation, TargetLocation) / MovingTime;

		FVector NewLocation = FMath::VInterpConstantTo(CurrentLocation, TargetLocation, DeltaTime, Speed);

		GetOwner()->SetActorLocation(NewLocation);
	}
	else if (!Moved)
	{
		FVector CurrentLocation = GetOwner()->GetActorLocation();

		float Speed = FVector::Dist(StartLocation, TargetLocation) / MovingTime;

		FVector NewLocation = FMath::VInterpConstantTo(CurrentLocation, StartLocation, DeltaTime, Speed);

		GetOwner()->SetActorLocation(NewLocation);
	}

}