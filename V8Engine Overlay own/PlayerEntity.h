#include "stdafx.h"

struct PlayerEntity
{
	struct tPlayerEntityInfo
	{
		D3DXVECTOR3 Origin;
		std::string EntityType;
	} Variables;
	
	struct PlayerEntityFunctions
	{
		void GetPlayerEntityInfo(tPlayerEntityInfo* PlayerEntityInfo, DWORD dwFirstEntity);
	} Functions;
};

extern PlayerEntity pPlayerEntity;