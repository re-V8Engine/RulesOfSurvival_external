#include "stdafx.h"

void MemoryHacks::Speedhack()
{
	if (GetAsyncKeyState(0x6E) < 0)
	{
		while (GetAsyncKeyState(0x6E) < 0);
		{
			Sleep(100);
		}
		if (pGlobalVariables.Settings.Speedhack == false)
		{
			pEngine.Memory.Write<FLOAT>(&pGlobalVariables.Settings.SpeedON, pEngine.BaseAddress + pGlobalVariables.Offsets.MoveSpeed);
			pGlobalVariables.Settings.Speedhack = true;
			pEngine.Memory.Read<FLOAT>(&pGlobalVariables.Settings.Speed, pEngine.BaseAddress + pGlobalVariables.Offsets.MoveSpeed);
			pGlobalVariables.Settings.SpeedStatus = "120";//std::cout << "Speedhack ON!" << std::endl;
		}
		else if (pGlobalVariables.Settings.Speedhack == true)
		{
			pEngine.Memory.Write<FLOAT>(&pGlobalVariables.Settings.SpeedOFF, pEngine.BaseAddress + pGlobalVariables.Offsets.MoveSpeed);
			pGlobalVariables.Settings.Speedhack = false;
			pEngine.Memory.Read<FLOAT>(&pGlobalVariables.Settings.Speed, pEngine.BaseAddress + pGlobalVariables.Offsets.MoveSpeed);
			pGlobalVariables.Settings.SpeedStatus = "60(Default)";//std::cout << "Speedhack OFF!" << std::endl;
		}
	}

	if (GetAsyncKeyState(0x6B) < 0)
	{
		while (GetAsyncKeyState(0x6B) < 0);
		{
			Sleep(100);
		}
		pEngine.Memory.Read<FLOAT>(&pGlobalVariables.Settings.Speed, pEngine.BaseAddress + pGlobalVariables.Offsets.MoveSpeed);
		pGlobalVariables.Settings.Speed += 60;
		pEngine.Memory.Write<FLOAT>(&pGlobalVariables.Settings.Speed, pEngine.BaseAddress + pGlobalVariables.Offsets.MoveSpeed);
		pEngine.Memory.Read<FLOAT>(&pGlobalVariables.Settings.Speed, pEngine.BaseAddress + pGlobalVariables.Offsets.MoveSpeed);

	}
}

void MemoryHacks::Noclip()
{
	if (GetAsyncKeyState(VK_NUMPAD0) < 0)
	{
		while (GetAsyncKeyState(VK_NUMPAD0) < 0);
		{
			Sleep(100);
		}
		if (pGlobalVariables.Settings.WallThru == false)
		{
			pEngine.Memory.Write<FLOAT>(&pGlobalVariables.Settings.WallThruON, pEngine.BaseAddress + pGlobalVariables.Offsets.WallThru);
			pGlobalVariables.Settings.WallThru = true;
			pGlobalVariables.Settings.NoclipStatus = "ON";//std::cout << "No Clip ON!" << std::endl;
		}
		else if (pGlobalVariables.Settings.WallThru == true)
		{
			pEngine.Memory.Write<FLOAT>(&pGlobalVariables.Settings.WallThruOFF, pEngine.BaseAddress + pGlobalVariables.Offsets.WallThru);
			pGlobalVariables.Settings.WallThru = false;
			pGlobalVariables.Settings.NoclipStatus = "OFF";//std::cout << "No Clip OFF!" << std::endl;
		}
	}
}

void MemoryHacks::WalkUnderwater()
{
	if (GetAsyncKeyState(VK_NUMPAD1) < 0)
	{
		while (GetAsyncKeyState(VK_NUMPAD1) < 0);
		{
			Sleep(100);
		}
		if (pGlobalVariables.Settings.SuperJump == false)
		{
			pEngine.Memory.Write<FLOAT>(&pGlobalVariables.Settings.WalkUnderwaterON, pEngine.BaseAddress + pGlobalVariables.Offsets.WalkUnderwater);
			pGlobalVariables.Settings.WalkUnderwaterStatus = "ON";
			//pGlobalVariables.Settings.JumpHeight = 159.0f;
			//std::cout << "SuperJump ON!" << std::endl;
		}
		else if (pGlobalVariables.Settings.SuperJump == true)
		{
			pEngine.Memory.Write<FLOAT>(&pGlobalVariables.Settings.WalkUnderwaterOFF, pEngine.BaseAddress + pGlobalVariables.Offsets.WalkUnderwater);
			pGlobalVariables.Settings.WalkUnderwaterStatus = "OFF";
			//pGlobalVariables.Settings.JumpHeight = 109.0f;
			//std::cout << "SuperJump OFF!" << std::endl;
		}
	}

	/*if (GetAsyncKeyState(VK_F9) < 0)
	{
		while (GetAsyncKeyState(VK_F9) < 0);
		{
			Sleep(100);
		}
		pEngine.Memory.ReadOffset<FLOAT>(&pGlobalVariables.Settings.JumpHeight, pEngine.BaseAddress + pGlobalVariables.Offsets.Physics, 6, 0x14, 0, 0x40, 0, 0x10, 0x50);
		pGlobalVariables.Settings.JumpHeight += 10;
		pEngine.Memory.WriteOffset<FLOAT>(&pGlobalVariables.Settings.JumpHeight, pEngine.BaseAddress + pGlobalVariables.Offsets.Physics, 6, 0x14, 0, 0x40, 0, 0x10, 0x50);
		pEngine.Memory.ReadOffset<FLOAT>(&pGlobalVariables.Settings.JumpHeight, pEngine.BaseAddress + pGlobalVariables.Offsets.Physics, 6, 0x14, 0, 0x40, 0, 0x10, 0x50);

	}*/
}

void MemoryHacks::GraveMode()
{
	if (GetAsyncKeyState(VK_F5) < 0)
	{
		while (GetAsyncKeyState(VK_F5) < 0);
		{
			Sleep(100);
		}
		if (pGlobalVariables.Settings.WallThru == false)
		{
			pEngine.Memory.Write<FLOAT>(&pGlobalVariables.Settings.WallThruON, pEngine.BaseAddress + pGlobalVariables.Offsets.WallThru);
			pGlobalVariables.Settings.WallThru = true;
			pGlobalVariables.Settings.NoclipStatus = "ON";//std::cout << "No Clip ON!" << std::endl;
		}
		else if (pGlobalVariables.Settings.WallThru == true)
		{
			pEngine.Memory.Write<FLOAT>(&pGlobalVariables.Settings.WallThruOFF, pEngine.BaseAddress + pGlobalVariables.Offsets.WallThru);
			pGlobalVariables.Settings.WallThru = false;
			pGlobalVariables.Settings.NoclipStatus = "OFF";//std::cout << "No Clip OFF!" << std::endl;
		}
	}
}

void MemoryHacks::Gravity()
{
	if (GetAsyncKeyState(VK_F10) < 0)
	{
		while (GetAsyncKeyState(VK_F10) < 0);
		{
			Sleep(100);
		}
		pEngine.Memory.ReadOffset<FLOAT>(&pGlobalVariables.Settings.fGravity, pEngine.BaseAddress + pGlobalVariables.Offsets.Physics, 6, 0x14, 0, 0x40, 0, 0x10, 0x64);
		pGlobalVariables.Settings.fGravity += 10;
		pEngine.Memory.WriteOffset<FLOAT>(&pGlobalVariables.Settings.fGravity, pEngine.BaseAddress + pGlobalVariables.Offsets.Physics, 6, 0x14, 0, 0x40, 0, 0x10, 0x64);
		pEngine.Memory.ReadOffset<FLOAT>(&pGlobalVariables.Settings.fGravity, pEngine.BaseAddress + pGlobalVariables.Offsets.Physics, 6, 0x14, 0, 0x40, 0, 0x10, 0x64);

	}
	if (GetAsyncKeyState(VK_F11) < 0)
	{
		while (GetAsyncKeyState(VK_F11) < 0);
		{
			Sleep(100);
		}
		pEngine.Memory.ReadOffset<FLOAT>(&pGlobalVariables.Settings.fGravity, pEngine.BaseAddress + pGlobalVariables.Offsets.Physics, 6, 0x14, 0, 0x40, 0, 0x10, 0x64);
		pGlobalVariables.Settings.fGravity -= 10;
		pEngine.Memory.WriteOffset<FLOAT>(&pGlobalVariables.Settings.fGravity, pEngine.BaseAddress + pGlobalVariables.Offsets.Physics, 6, 0x14, 0, 0x40, 0, 0x10, 0x64);
		pEngine.Memory.ReadOffset<FLOAT>(&pGlobalVariables.Settings.fGravity, pEngine.BaseAddress + pGlobalVariables.Offsets.Physics, 6, 0x14, 0, 0x40, 0, 0x10, 0x64);

	}
}

void MemoryHacks::Position()
{
	pEngine.Memory.ReadOffset<D3DXVECTOR3>(&pGlobalVariables.Settings.PhysicsOrigin, pEngine.BaseAddress + pGlobalVariables.Offsets.Physics, 6, 0x14, 0, 0x40, 0, 0x10, 0x20);
	if (GetAsyncKeyState(VK_NUMPAD2) < 0)
	{
		while (GetAsyncKeyState(VK_NUMPAD2) < 0);
		{
			Sleep(100);
		}
		pGlobalVariables.Settings.PhysicsOrigin[2] -= 50;
		pEngine.Memory.WriteOffset<D3DXVECTOR3>(&pGlobalVariables.Settings.PhysicsOrigin, pEngine.BaseAddress + pGlobalVariables.Offsets.Physics, 6, 0x14, 0, 0x40, 0, 0x10, 0x20);
	}
	if (GetAsyncKeyState(VK_NUMPAD4) < 0)
	{
		while (GetAsyncKeyState(VK_NUMPAD4) < 0);
		{
			Sleep(100);
		}
		pGlobalVariables.Settings.PhysicsOrigin[0] -= 50;
		pEngine.Memory.WriteOffset<D3DXVECTOR3>(&pGlobalVariables.Settings.PhysicsOrigin, pEngine.BaseAddress + pGlobalVariables.Offsets.Physics, 6, 0x14, 0, 0x40, 0, 0x10, 0x20);
	}
	if (GetAsyncKeyState(VK_NUMPAD8) < 0)
	{
		while (GetAsyncKeyState(VK_NUMPAD8) < 0);
		{
			Sleep(100);
		}
		pGlobalVariables.Settings.PhysicsOrigin[2] += 50;
		pEngine.Memory.WriteOffset<D3DXVECTOR3>(&pGlobalVariables.Settings.PhysicsOrigin, pEngine.BaseAddress + pGlobalVariables.Offsets.Physics, 6, 0x14, 0, 0x40, 0, 0x10, 0x20);
	}
	if (GetAsyncKeyState(VK_NUMPAD6) < 0)
	{
		while (GetAsyncKeyState(VK_NUMPAD6) < 0);
		{
			Sleep(100);
		}
		pGlobalVariables.Settings.PhysicsOrigin[0] += 50;
		pEngine.Memory.WriteOffset<D3DXVECTOR3>(&pGlobalVariables.Settings.PhysicsOrigin, pEngine.BaseAddress + pGlobalVariables.Offsets.Physics, 6, 0x14, 0, 0x40, 0, 0x10, 0x20);
	}
	if (GetAsyncKeyState(VK_NUMPAD7) < 0)
	{
		while (GetAsyncKeyState(VK_NUMPAD7) < 0);
		{
			Sleep(100);
		}
		pGlobalVariables.Settings.PhysicsOrigin[1] += 50;
		pEngine.Memory.WriteOffset<D3DXVECTOR3>(&pGlobalVariables.Settings.PhysicsOrigin, pEngine.BaseAddress + pGlobalVariables.Offsets.Physics, 6, 0x14, 0, 0x40, 0, 0x10, 0x20);
	}
	if (GetAsyncKeyState(VK_NUMPAD9) < 0)
	{
		while (GetAsyncKeyState(VK_NUMPAD9) < 0);
		{
			Sleep(100);
		}
		pGlobalVariables.Settings.PhysicsOrigin[1] -= 50;
		pEngine.Memory.WriteOffset<D3DXVECTOR3>(&pGlobalVariables.Settings.PhysicsOrigin, pEngine.BaseAddress + pGlobalVariables.Offsets.Physics, 6, 0x14, 0, 0x40, 0, 0x10, 0x20);
	}
}
void MemoryHacks::Reset()
{
	pEngine.Memory.Write<FLOAT>(&pGlobalVariables.Settings.SpeedOFF, pEngine.BaseAddress + 0x01761A20);
	pGlobalVariables.Settings.Speedhack = false;
	//std::cout << "Speedhack OFF!" << std::endl;

	pEngine.Memory.Write<FLOAT>(&pGlobalVariables.Settings.WallThruOFF, pEngine.BaseAddress + 0x017586A8);
	pGlobalVariables.Settings.WallThru = false;
	//std::cout << "No Clip OFF!" << std::endl;

}