// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenDoor.h"
#include "DrawDebugHelpers.h"
#include "Runtime/Engine/Classes/Engine/TriggerVolume.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	PrimaryComponentTick.bCanEverTick = true;
	Owner = GetOwner();
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{

	Super::BeginPlay();
	
	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
	ClosedAngle = Owner->GetActorRotation().Yaw;
	OpenAngle = ClosedAngle + OpenAngle;

	
}

void UOpenDoor::OpenDoor(float Rotation) {

	FRotator ActorRotation = Owner->GetActorRotation();
	ActorRotation.Yaw = Rotation;
	Owner->SetActorRotation(ActorRotation);
}

void UOpenDoor::CloseDoor() {

	FRotator ActorRotation = Owner->GetActorRotation();
	ActorRotation.Yaw = ClosedAngle;
	Owner->SetActorRotation(ActorRotation);
}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (PressurePlate->IsOverlappingActor(ActorThatOpens)) 
	{
		OpenDoor(OpenAngle);
	}
	else 
	{
		CloseDoor();
	}
}

