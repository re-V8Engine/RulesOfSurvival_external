#include "stdafx.h"

struct ESP 
{
	LocalPlayer::tLocalPlayerInfo LocalPlayerInfo;
	PlayerEntity::tPlayerEntityInfo PlayerEntityInfo;
	//LocalPlayer::tLocalPlayerInfo LocPlayerInf;
	//PlayerEntity::tPlayerEntityInfo PlaEntInf;

	struct ESPFunctions 
	{
		D3DXVECTOR2 WorldToScreen(D3DXVECTOR3 EnemyPosition, LocalPlayer::tDataStructs::tViewMatrix ViewMatrix);
		void DrawCircleCrosshair();
		void DrawType();
		void Tick();
	} Functions;
};

extern ESP pESP;