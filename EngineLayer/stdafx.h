// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

// TODO: reference additional headers your program requires here
#include <windows.h>

#pragma warning(disable : 4996)
#include "SFConstant.h"
#include "SFStructure.h"
#include "BasePacket.h"
#include "SFMacro.h"
#include "SFSinglton.h"
//#include "PacketID.h"

#include <ace/ace.h>
#include <ace/Thread_Manager.h>
#include <ace/Thread_Mutex.h>
#include <ace/Proactor.h>
#include <ace/Task.h>

#define GLOG_NO_ABBREVIATED_SEVERITIES

//#pragma warning(disable : 4244)
//#include <glog/logging.h>
//#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
//#include "ChatPacket.pb.h"

#include <tchar.h>
#include "Macro.h"
#include "SFString.h"
#include "SFCompressLzf.h"
#include "SFPacketProtocol.H"
#include "SFBridgeThread.h"
//#pragma comment(lib, "libglog.lib")

