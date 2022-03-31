// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Komodo.h"
#include "KManagerBase.h"
#include "KWindowManager.generated.h"

/**
 * 
 */
UCLASS()
class KOMODO_API UKWindowManager : public UKManagerBase
{
	GENERATED_BODY()
	
public:
	virtual void Initialize_Manager() override;

	
	UFUNCTION(BlueprintCallable)
	void CreateWindow(EWindow_Table eWindowValue);
	void AddNewWindow(const bool bFullWindow);



public:
	UFUNCTION(BlueprintCallable)
	class AKWindow* Get_Recent_Window();

protected:
	UPROPERTY()
	TArray<class AKWindow*> CreatedWindows_;

	UPROPERTY()
	TWeakObjectPtr<class AKWindow> RecentWindow_;

	//TArray<class UKPage> Ma
};
