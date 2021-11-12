// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PrioritizedAITile.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class GAMEASSIGNMENT_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

		UFUNCTION(BlueprintCallable, Category = "File I/O")
		static FString LoadFileToString(FString fileName);

	UFUNCTION(BlueprintCallable, Category = "File I/O")
		static void SaveStringArrayToFile(const TArray<FString>& lines);

	UFUNCTION(BlueprintCallable, Category = "Array Sort")
		static void Tile_Priority_Sort(UPARAM(ref) TArray<FPrioritizedAITile> &array_to_sort, TArray<FPrioritizedAITile> &sorted_array);
};
