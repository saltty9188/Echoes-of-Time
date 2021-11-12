// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AITile.h"
#include "PrioritizedAITile.generated.h"

USTRUCT(BlueprintType)
struct FPrioritizedAITile
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FAITile Tile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Priority;

	FPrioritizedAITile() : FPrioritizedAITile({}, 0)
	{}

	FPrioritizedAITile(const FAITile &Tile, float Priority): Tile(Tile), Priority(Priority)
	{}

	FPrioritizedAITile(const FPrioritizedAITile &other): FPrioritizedAITile(other.Tile, other.Priority)
	{}

	bool operator==(const FPrioritizedAITile& other) const
	{
		return (Tile == other.Tile) && (Priority == other.Priority);
	}

	bool operator<(const FPrioritizedAITile& other) const
	{
		return Priority < other.Priority;
	}

	bool operator>(const FPrioritizedAITile& other) const
	{
		return other < *this;
	}
};
