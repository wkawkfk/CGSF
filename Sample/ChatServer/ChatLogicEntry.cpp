#include "StdAfx.h"
#include "ChatLogicEntry.h"
#include "ChatUser.h"
#include "PacketID.h"
#include "SFSinglton.h"
#include <iostream>
#include "SFEngine.h"
#include "SFProtobufPacket.h"

using namespace google;

extern SFEngine* g_pEngine;

ChatLogicEntry::ChatLogicEntry(void)
{
}

ChatLogicEntry::~ChatLogicEntry(void)
{
}

BOOL ChatLogicEntry::ProcessPacket(BasePacket* pPacket )
{
	switch (pPacket->GetPacketType())
	{
	case SFPacket_Connect:
		{	
			OnConnectPlayer(pPacket->GetOwnerSerial());
		}
		break;

	case SFPacket_Data:
		{	
			OnPlayerData(pPacket);
		}
		break;

	case SFPacket_Disconnect:
		{	
			OnDisconnectPlayer(pPacket->GetOwnerSerial());
		}
		break;

	case SFPacket_Timer:
		{	
			//OnTimer(pCommand->GetOwnerSerial());
		}
		break;

	default:
		return FALSE;
	}

	return TRUE;
}

BOOL ChatLogicEntry::OnConnectPlayer( int Serial )
{
	ChatUser* pUser = new ChatUser();
	pUser->SetSerial(Serial);

	m_ChatUserMap.insert(ChatUserMap::value_type(Serial, pUser));

	return TRUE;
}

BOOL ChatLogicEntry::OnDisconnectPlayer( int Serial )
{
	ChatUserMap::iterator iter = m_ChatUserMap.find(Serial);

	if(iter == m_ChatUserMap.end())
	{
		SFASSERT(0);
		return FALSE;
	}

	ChatUser* pUser = iter->second;

	delete pUser;

	m_ChatUserMap.erase(iter);

	return TRUE;
}

BOOL ChatLogicEntry::OnPlayerData( BasePacket* pPacket )
{
	if(pPacket->GetPacketID() == CGSF::ChatReq)
	{
		SFProtobufPacket<ChatPacket::Chat>* pChat = (SFProtobufPacket<ChatPacket::Chat>*)pPacket;
		std::cout << pChat->GetData().chatmessage() << std::endl;

		
		/*SFPacket Packet;
		Packet.SetPacketID(pPacket->GetPacketID());
		Packet.MakePacket(pPacket->GetDataBuffer(), pPacket->GetDataSize(), CGSF_PACKET_OPTION);

		Broadcast(&Packet, pPacket->GetOwnerSerial());*/

		SFProtobufPacket<ChatPacket::Chat> ChatRes(CGSF::ChatRes);
		ChatRes.GetData().set_chatmessage(pChat->GetData().chatmessage());
		Broadcast(&ChatRes);

		return TRUE;
	}

	return FALSE;
}

BOOL ChatLogicEntry::SendRequest(BasePacket* pPacket)
{
	g_pEngine->SendRequest(pPacket);

	return TRUE;
}

BOOL ChatLogicEntry::Broadcast( BasePacket* pPacket)
{
	ChatUserMap::iterator iter = m_ChatUserMap.begin();

	for(;iter != m_ChatUserMap.end(); iter++)
	{
		//if(pPacket->GetOwnerSerial() != iter->first)
		pPacket->SetOwnerSerial(iter->first);	
		SendRequest(pPacket);
	}

	return TRUE;
}