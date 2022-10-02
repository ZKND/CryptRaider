// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponent.h"
#include "Mover.h"

// Sets default values for this component's properties
UTriggerComponent::UTriggerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Display, TEXT("Trigger Component is here"));

}

void UTriggerComponent::OpenLinkedDoor() const
{
	UE_LOG(LogTemp, Display, TEXT("Door unlocking"));
	UMover* LinkedMover = LinkedDoor->FindComponentByClass<UMover>();
	LinkedMover->Moved = true;
}


void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	TArray<AActor*> Actors;

	GetOverlappingActors(Actors);

	for (AActor* Actor : Actors)
	{
		if (Actor->ActorHasTag(AcceptableActorTag))
		{
			OpenLinkedDoor();
			Actor->GetRootComponent()->SetMobility(EComponentMobility::Static);
		}
	}
}

