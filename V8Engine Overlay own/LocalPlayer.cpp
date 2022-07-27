#include "stdafx.h"

void LocalPlayer::LocalPlayerFunctions::GetLocalPlayerInfo(tLocalPlayerInfo* LocalPlayerInfo)
{
	pEngine.Memory.Read<tDataStructs::tViewMatrix>(&LocalPlayerInfo->ViewMatrix, pEngine.BaseAddress + 0x219C858);
}