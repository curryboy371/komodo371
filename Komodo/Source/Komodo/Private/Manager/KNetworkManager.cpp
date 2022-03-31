// Fill out your copyright notice in the Description page of Project Settings.


#include "KNetworkManager.h"

#include "KUtill.h"
#include "KGameInstance.h"
#include "Setting/KDeveloperSettings.h"

#include "KTextTransition.h"

void UKNetworkManager::Initialize_Manager()
{

}

void UKNetworkManager::Call(const FString& Param)
{
    UKGameInstance* KGameInstance = UKUtill::GetKGameInstance();
    if (KGameInstance == nullptr)
    {
        return;
    }

    UKDeveloperSettings* KDeveloperSettings = KGameInstance->GetDeveloperSettings();
    if (KDeveloperSettings == nullptr)
    {
        return;
    }
   
    FString id = UKTextTransition::TransitStringParam(TEXT("id"), Param);
    FString password = UKTextTransition::TransitStringParam(TEXT("pw"), Param);
    
    try
    {
        std::string str_ip = TCHAR_TO_ANSI(*KDeveloperSettings->GetServerIP());

        CustomClient c;
        c.Connect(str_ip, KDeveloperSettings->GetServerPort());
    
        bool quit = false;
    
        FString chat = TEXT("zzzzzz");
    
        std::thread msg_recv([&c]() {
    
            while (1)
            {
                if (!c.Incoming().empty())
                {
                    auto msg = c.Incoming().pop_front().msg;
    
                    //msg 수신
                    switch (msg.header.id)
                    {
                    case protocol::kTextSend:
                    {
                        auto text = SamplePacket::GettextREQ(msg.body.data());
                        UE_LOG(LogTemp, Log, TEXT("kTextSend"));

                        //std::cout << text->text()->c_str() << std::endl;
                    }
                    break;
    
                    }
                }
            }});
    
        while (!quit)
        {
            if (c.IsConnected())
            {
                if (bloggedin_)
                {
                    //std::getline(std::cin >> std::ws, chat);
    
                    // 서버로 메세지 전송
                    {
                        net::Message<protocol> msg;
                        msg.header.id = protocol::kTextSend;
                        flatbuffers::FlatBufferBuilder builder(1024);
                        std::string str_chat = TCHAR_TO_ANSI(*chat);
                        auto text = builder.CreateString(str_chat);
                        SamplePacket::textREQBuilder text_req_builder(builder);
                        text_req_builder.add_text(text);
                        auto ack = text_req_builder.Finish();
                        builder.Finish(ack);
                        msg << builder;
                        c.Send(msg);
                        UE_LOG(LogTemp, Log, TEXT("Send"));
                    }
                }
                else
                {

                    // 서버로 메세지 전송
                    {
                        net::Message<protocol> msg;
                        msg.header.id = protocol::kCreateAccount;
                        flatbuffers::FlatBufferBuilder builder(1024);
                        std::string str_id = TCHAR_TO_ANSI(*id);
                        std::string str_password = TCHAR_TO_ANSI(*password);

                        auto login_id = builder.CreateString(str_id);
                        auto login_password = builder.CreateString(str_password);
                        SamplePacket::Login_reqBuilder login_req_builder(builder);
                        login_req_builder.add_id(login_id);
                        login_req_builder.add_pw(login_password);
                        auto ack = login_req_builder.Finish();
                        builder.Finish(ack);
                        msg << builder;
                        c.Send(msg);
                        UE_LOG(LogTemp, Log, TEXT("Send"));

                    }
                }
            }
            else
            {
                //std::cout << "Server Down" << std::endl;
                quit = true;
            }
        }
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
