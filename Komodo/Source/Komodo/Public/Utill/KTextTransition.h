// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "KTextTransition.generated.h"

/**
 * 
 */
UCLASS()
class KOMODO_API UKTextTransition : public UObject
{
	GENERATED_BODY()
	
public:
	static FString TransitStringParam(const FString& inKey, const FString& inParam);
};
