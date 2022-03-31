// Fill out your copyright notice in the Description page of Project Settings.


#include "KPrefab.h"

void UKPrefab::SetVisible(const bool bSet)
{
	if (bVisible_ == bSet)
	{
		return;
	}

	bVisible_ = bSet;

	if (bVisible_)
	{
		AddToViewport();
	}
	else
	{
		SetVisibility(ESlateVisibility::Collapsed);
	}
}