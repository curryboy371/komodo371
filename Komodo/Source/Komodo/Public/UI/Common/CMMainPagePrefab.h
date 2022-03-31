// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/KPrefab.h"
#include "Engine/Texture.h"
#include "CMMainPagePrefab.generated.h"

/**
 * 
 */
UCLASS()
class KOMODO_API UCMMainPagePrefab : public UKPrefab
{
	GENERATED_BODY()
public:
	UCMMainPagePrefab();

public:
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CM_MainPage")
	//UTexture bg_texture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CM_MainPage")
	FText title_text_;


};
