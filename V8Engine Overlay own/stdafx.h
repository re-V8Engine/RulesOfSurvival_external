#pragma once

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif         // Exclude rarely-used stuff from Windows headers



// Windows Header Files:
#include <map>
#include <windows.h>
#include <iostream>
#include <d3d9.h>
#include <d3dx9.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#include <dwmapi.h>
#pragma comment (lib, "dwmapi.lib")
#include <TlHelp32.h>
#include <string>
#include <winternl.h>
#include <winioctl.h>
#include <Shlwapi.h>
#include "Engine.h"
#include "GlobalVariables.h"
#include "Overlay.h"
#include "DirectX.h"
#include "MemHacks.h"
#include "PlayerEntity.h"
#include "LocalPlayer.h"
#include "ESP.h"
//#include "Classes.h"