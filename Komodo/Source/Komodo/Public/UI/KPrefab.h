// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "KPrefab.generated.h"

/**
 * 
 */
UCLASS()
class KOMODO_API UKPrefab : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void SetVisible(const bool bSet);

private:
	//print on viewprot or not
	bool bVisible_ = false;
};
