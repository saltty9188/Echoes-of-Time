// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Crc.h"
#include "Chaos/Array.h"
#include "Templates/TypeHash.h"
#include "AITile.generated.h"

USTRUCT(BlueprintType)
struct FAITile
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool CanPass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 X;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Y;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Index;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int32> NeighbourIndices;

	FAITile(): FAITile(true, 0, 0, {})
	{}

	FAITile(bool CanPass, int32 X, int32 Y, TArray<int32> Neighbours = {}): CanPass(CanPass), X(X), Y(Y), NeighbourIndices(Neighbours)
	{}

	FAITile(const FAITile &other): FAITile(other.CanPass, other.X, other.Y, other.NeighbourIndices)
	{}

	bool operator==(const FAITile& other) const
	{
		return Equals(other);
	}

	bool Equals(const FAITile& other) const
	{
		return (CanPass == other.CanPass) && (X == other.X) && (Y == other.Y) && (NeighbourIndices == other.NeighbourIndices);
	}

	friend uint32 GetTypeHash(const FAITile& Thing)
	{
		uint32 Hash = FCrc::MemCrc32(&Thing, sizeof(FAITile));//GetTypeHash(Thing.X) + GetTypeHash(Thing.Y) + GetTypeHash(Thing.NeighbourIndices);
		return Hash;
	}
};
