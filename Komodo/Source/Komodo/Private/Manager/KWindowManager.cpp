// Fill out your copyright notice in the Description page of Project Settings.


#include "KWindowManager.h"

#include "KUtill.h"
#include "KTableManager.h"

#include "KWindow.h"

void UKWindowManager::Initialize_Manager()
{
	CreatedWindows_.Empty();
	RecentWindow_ = nullptr;
	


	CreateKWindow(EWindow_Table::TITLE_WINDOW);
}

void UKWindowManager::CreateKWindow(EWindow_Table eWindowValue)
{
	if (UKUtill::GetKGameInstance())
	{
		UKTableManager* TableMgr = UKUtill::GetKGameInstance()->GetTableManager();
		if (TableMgr == nullptr)
		{
			return;
		}

		FWindowTableEntity* WindowEntity = TableMgr->Get_Window_Table(int32(eWindowValue));
		if (WindowEntity == nullptr)
		{
			return;
		}

		//__TODO(If_this_window_can_duplicate);
		//WindowEntity->bisduplicated
		for (auto& window : CreatedWindows_)
		{
			if (window)
			{
				if (eWindowValue == window->Get_Window_ID())
				{

				}
			}
		}


		// Get Blueprint Class Path
		// Class'/path/name.name_C'
		TArray<FString> StrArr;
		if (WindowEntity->path.ParseIntoArray(StrArr, TEXT("/"), true) <= 0)
		{
			return;
		}

		FString fileName = StrArr.Last();
		FString path = FString::Printf(TEXT("Class'%s.%s_C'"), *WindowEntity->path, *fileName);
		
		UClass* GeneratedBP = Cast<UClass>(StaticLoadObject(UClass::StaticClass(), NULL, *path)); // Create BPClass
		if (GeneratedBP == nullptr)
		{
			return;
		}

		UWorld* World = GEngine->GameViewport->GetWorld();
		if (World == nullptr)
		{
			return;
		}

		FTransform WinLocation;
		AKWindow* NewWindow = World->SpawnActor<AKWindow>(GeneratedBP, WinLocation);
		if (NewWindow)
		{
			//WindowEntity->bisfullscreen
			AddNewWindow(true /*temp*/);
			NewWindow->CreatePage();
			NewWindow->Initialize_Window();

			RecentWindow_ = NewWindow;
			CreatedWindows_.Add(NewWindow);
		}
	}
}

// 새로운 Window가 출력되었을 때 기존에 visible되던 window 처리할 함수
void UKWindowManager::AddNewWindow(const bool bFullWindow)
{
	if (bFullWindow)
	{
		for (auto& window : CreatedWindows_)
		{
			if (window)
			{
				window->SetVisibleWindow(false);
			}
		}
	}

}

AKWindow* UKWindowManager::Get_Recent_Window()
{
	if (RecentWindow_.IsValid())
	{
		return RecentWindow_.Get();
	}
	
	return nullptr;
}
