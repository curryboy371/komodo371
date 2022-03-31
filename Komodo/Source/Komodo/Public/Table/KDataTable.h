// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "KDataTable.generated.h"

//WindowTable
USTRUCT(BlueprintType)
struct FWindowTableEntity : public FTableRowBase
{
	GENERATED_BODY()

	public:
		FWindowTableEntity() : id(1), path(TEXT("")), name(TEXT("")) {}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	int32 id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	FString path;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	FString name;
};


UCLASS()
class KOMODO_API AKDataTable : public AActor
{
	GENERATED_BODY()
	
};
