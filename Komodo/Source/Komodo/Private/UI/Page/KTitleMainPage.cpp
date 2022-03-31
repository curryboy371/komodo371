// Fill out your copyright notice in the Description page of Project Settings.


#include "KTitleMainPage.h"

#include "KGameInstance.h"

#include "Manager/KNetworkManager.h"

void UKTitleMainPage::OnLoginButton()
{
	if (GetGameInstance())
	{
		UKGameInstance* KGameInstance = Cast<UKGameInstance>(GetGameInstance());
		if (KGameInstance)
		{
			UKNetworkManager* NetworkMgr = KGameInstance->GetNetworkManager();

			if (NetworkMgr)
			{
				NetworkMgr->Call(AccountInfo_);
			}
		}
	}


}