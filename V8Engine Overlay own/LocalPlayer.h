#include "stdafx.h"

volatile struct LocalPlayer
{
	struct tDataStructs
	{
		struct tViewMatrix
		{
			float Matrix[4][4];
		};
	};

	struct tLocalPlayerInfo
	{
		D3DXVECTOR3 Origin;
		std::string EntityType;
		LocalPlayer::tDataStructs::tViewMatrix ViewMatrix;
	} Variables;

	struct LocalPlayerFunctions
	{
		void GetLocalPlayerInfo(tLocalPlayerInfo* LocalPlayerInfo);
	} Functions;
};

extern LocalPlayer pLocalPlayer;