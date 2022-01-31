 // Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"

FString UMyBlueprintFunctionLibrary::HealthUpdate(float a)
{
	int foo = a;

	return FString(FString::Printf(TEXT("Health Update. You got %d"), foo ));
}
