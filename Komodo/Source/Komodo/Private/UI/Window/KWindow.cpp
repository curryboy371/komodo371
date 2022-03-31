// Fill out your copyright notice in the Description page of Project Settings.


#include "KWindow.h"
#include "KPage.h"

// Manager
//#include "Manager\KWindowManager.h"

// Sets default values
AKWindow::AKWindow()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AKWindow::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AKWindow::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AKWindow::Initialize_Window(const bool bActive/* = true*/, const bool bVisible/* = true*/)
{
	MainPageSources_.Empty();
	ExtraPageSources_.Empty();
	MainPages_.Empty();
	ExtraPages_.Empty();

	SetActiveWindow(bActive);
	SetVisibleWindow(bVisible);
}

void AKWindow::CreatePage()
{
	// create page 
	// copy sorce > pages 
	
	UWorld* World = GEngine->GameViewport->GetWorld();
	if (World == nullptr)
	{
		return;
	}

	for (auto& src : MainPageSources_)
	{
		
		UUserWidget* page_widget = CreateWidget<UUserWidget>(World, src);
		if (page_widget)
		{

			UKPage* page = Cast<UKPage>(page_widget);
			if (page)
			{
				page->SetVisible(true);
				MainPages_.Add(page);
			}
		}
	}

	int32 PageSize = MainPages_.Num();
	//if (PageSize == INVALID_SIZE)
	//{
	//
	//}
}

void AKWindow::SetActiveWindow(const bool bSet)
{
	if (bActive_ == bSet)
	{
		return;
	}

	bActive_ = bSet;

	if (bActive_)
	{

	}
	else
	{

	}
}

void AKWindow::SetVisibleWindow(const bool bSet)
{
	if (bVisible_ == bSet)
	{
		return;
	}

	bVisible_ = bSet;

	if (bVisible_ && bActive_)
	{
		for (auto& page : MainPages_)
		{
			if (page)
			{
				page->SetVisible(bSet);
			}
		}
	}
	else
	{

	}
}

