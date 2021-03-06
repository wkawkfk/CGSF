// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#pragma warning(disable : 4996)
#include <ace/ace.h>
#include <ace/Thread_Manager.h>
#include <ace/Thread_Mutex.h>
#include <ace/Proactor.h>
#include <ace/Task.h>

// TODO: reference additional headers your program requires here
///////////////////////////////////////////////////////////////////////////////////
#include <windows.h>
#include "SFConstant.h"
#include "SFStructure.h"
#include "SFMacro.h"
#include "PacketID.h"
#include "SFPacketStore.pb.h"

#pragma comment(lib, "zlib.lib")
#pragma comment(lib, "liblzf.lib")
#pragma comment(lib, "libprotobuf.lib")
//#pragma comment(lib, "tomcrypt.lib")
#ifdef _DEBUG
#pragma comment(lib, "aced.lib")
#else
#pragma comment(lib, "ace.lib")
#endif