// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"
#include <Runtime/Core/Public/Misc/Paths.h>
#include <Runtime/Core/Public/HAL/PlatformFilemanager.h>

FString UMyBlueprintFunctionLibrary::LoadFileToString(FString filename)
{
	FString directory = FPaths::ProjectContentDir();
	FString result = "";
	IPlatformFile& file = FPlatformFileManager::Get().GetPlatformFile();

	if (file.CreateDirectory(*directory))
	{
		FString myFile = directory + "/" + filename;
		FFileHelper::LoadFileToString(result, *myFile);
	}

	return result;
}

void UMyBlueprintFunctionLibrary::SaveStringArrayToFile(const TArray<FString>& lines)
{
	FString directory = FPaths::ProjectContentDir();
	IPlatformFile& file = FPlatformFileManager::Get().GetPlatformFile();

	if (file.CreateDirectory(*directory))
	{
		FString myFile = directory + "/Files/output.txt";
		FFileHelper::SaveStringArrayToFile(lines, *myFile);
	}
}

void UMyBlueprintFunctionLibrary::Tile_Priority_Sort(UPARAM(ref)TArray<FPrioritizedAITile>& array_to_sort, TArray<FPrioritizedAITile>& sorted_array)
{
   
    array_to_sort.Sort();       // If array will be sorted low to high use Unreal's "Sort" function

    sorted_array = array_to_sort;
}
