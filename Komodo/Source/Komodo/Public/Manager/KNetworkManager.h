// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Manager/KManagerBase.h"



#include <flatbuffers/flatbuffers.h>
#include <SamplePacket_generated.h>
#include <asio.hpp>


#include "net_client.h"

#include "KNetworkManager.generated.h"

/**
 * 
 */

enum class protocol : uint16_t {
	kTextSend,
	kLogin,
	kCreateAccount
};


class CustomClient : public net::ClientInterface<protocol>
{
public:

};

UCLASS()
class KOMODO_API UKNetworkManager : public UKManagerBase
{
	GENERATED_BODY()
	
public:

	virtual void Initialize_Manager() override;

	void Call(const FString& Param);



private:
	bool bloggedin_ = false;
};
