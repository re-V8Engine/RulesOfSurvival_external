#include "stdafx.h"

struct GlobalVariables
{
	GlobalVariables();
	struct  
	{
		DWORD Renderer = 0x02083518;
		DWORD LocalPlayer = 0x020EA28C;
		DWORD Client = 0x020E8590;
		DWORD ViewMatrix = 0x01EDB470;
		DWORD SceneContext = 0x01EDB470;

		//DWORD YGround = 0x0169D1E8;
		DWORD WallThru = 0x0175A6B8;
		DWORD MoveSpeed = 0x01763A30;
		DWORD Zoom = 0x01716BCC;
		DWORD WalkUnderwater = 0x039665C;

		DWORD Physics = 0x021D88E8;
		//DWORD PlayerColor = 0x01FA0838;

		//DWORD Grass = 0x01C3F19C; //0x01C25BBC;

		

	} Offsets;
	struct 
	{
		std::string TagetName;
		std::string TargetWindowName;
		std::string OverlayWindowName;
		std::string SpeedStatus = "OFF";
		std::string NoclipStatus = "OFF";
		std::string WalkUnderwaterStatus = "OFF";

		bool DESTROYALL;
		bool WallThru;
		bool Speedhack;
		bool SuperJump;
		bool Hide;

		float HideON;
		float HideOFF;

		float SpeedON;
		float SpeedOFF;
		float Speed;

		float WallThruON;
		float WallThruOFF;

		float WalkUnderwaterON;
		float WalkUnderwaterOFF;
		float JumpHeight;

		float fGravity;

		D3DXVECTOR3 Origin;
		D3DXVECTOR3 PhysicsOrigin;
	} Settings;
};

extern GlobalVariables pGlobalVariables;