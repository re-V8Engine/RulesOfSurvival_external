#include "stdafx.h"


Engine pEngine;
Overlay pOverlay;
GlobalVariables pGlobalVariables;
DirectX pDirectX;
ESP pESP;
MemoryHacks pMemHacks;
PlayerEntity pPlayerEntity;
LocalPlayer pLocalPlayer;
//ClientApp pClientApp;

//Memory hacks
DWORD WINAPI Thread2(LPVOID Params)
{
	pEngine.Thread2Active = true;

	pEngine.Memory.Read<FLOAT>(&pGlobalVariables.Settings.Speed, pEngine.BaseAddress + 0x01761A20);

	while (!pGlobalVariables.Settings.DESTROYALL)
	{
		pMemHacks.Speedhack();
		pMemHacks.Noclip();
		pMemHacks.Position();
		pMemHacks.WalkUnderwater();
		pMemHacks.Gravity();
		std::cout << "Speedhack[Num,]: " << pGlobalVariables.Settings.SpeedStatus << std::endl;
		std::cout << "Noclip[Num0]: " << pGlobalVariables.Settings.NoclipStatus << std::endl;
		std::cout << "SuperJump[F9+]: " << (int)pGlobalVariables.Settings.JumpHeight << std::endl;
		std::cout << "Gravity[F10+/F11-]: " << (int)pGlobalVariables.Settings.fGravity << std::endl;
		system("cls");
		Sleep(1);
	}
	pMemHacks.Reset();
	pEngine.Thread2Active = false;
	return 0;
}

//Drawing
DWORD WINAPI Thread1(LPVOID Params)
{
	pEngine.Thread1Active = true;
	while (!pGlobalVariables.Settings.DESTROYALL)
	{
		pOverlay.Functions.Refresh();
		Sleep(1);
	}
	pOverlay.Functions.Destruct();
	pDirectX.Functions.Destruct();
	pEngine.Thread1Active = false;
	return 0;	
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hInstancePrev, LPSTR CmdLine, int CmdShow)
{
	pEngine.Thread1Active = false;
	pGlobalVariables.Settings.WallThru = false;
	pGlobalVariables.Settings.Speedhack = false;
	pGlobalVariables.Settings.Hide = false;

	//LoadConsole()
	FILE *stream;
	AllocConsole();
	freopen_s(&stream,"CONIN$", "r", stdin);
	freopen_s(&stream,"CONOUT$", "w", stdout);
	std::cout << "Loading console...";
	std::cout << "OK!" << std::endl;
	//end


	std::cout << "Searching for game..." << std::endl;

	while (!pEngine.Process.Attach())
	{
		Sleep(100);
	}
	
	//Thread calls
	CreateThread(0, 0, &Thread1, 0, 0, 0);
	CreateThread(0, 0, &Thread2, 0, 0, 0);



	while (!pGlobalVariables.Settings.DESTROYALL)
	{
		if (GetAsyncKeyState(VK_F1) < 0 && GetAsyncKeyState(VK_CONTROL) < 0)
		{
			while (GetAsyncKeyState(VK_F1) < 0 && GetAsyncKeyState(VK_CONTROL) < 0);
			{
				Sleep(100);
			}
			pGlobalVariables.Settings.DESTROYALL = true;
		}

		if (GetAsyncKeyState(VK_NUMPAD3) < 0)
		{
			while (GetAsyncKeyState(VK_NUMPAD3) < 0);
			{
				Sleep(100);
			}
			while (pGlobalVariables.Settings.Hide == true)
			{
				pEngine.Memory.ReadOffset<FLOAT>(&pGlobalVariables.Settings.HideOFF, pEngine.BaseAddress + 0x020E80D4, 0x14);
				pGlobalVariables.Settings.HideOFF += pGlobalVariables.Settings.HideON;
				pEngine.Memory.WriteOffset<FLOAT>(&pGlobalVariables.Settings.SpeedON, pEngine.BaseAddress + 0x020E80D4,0x14);

			}
			if (pGlobalVariables.Settings.Hide == true)
			{
				//pEngine.Memory.Write<FLOAT>(&pGlobalVariables.Settings.SpeedOFF, pEngine.BaseAddress + 0x01761A20);
				pGlobalVariables.Settings.Speedhack = false;
				std::cout << "Hide OFF!" << std::endl;
			}
		}

		if (!pEngine.Memory.IsProcessActive())
		{
			pEngine.Process.Detach();
			exit(0);
			while (!pEngine.Process.Attach())
			{
				Sleep(100);
			}
		}
		Sleep(1);
	}

/*
	std::cout << "Base Address: 0x";
	std::cout << std::hex << std::stoi(std::to_string(pEngine.BaseAddress)) << std::endl;
	//pEngine.Memory.ReadOffset(&pEngine.dwFirstEntity, pEngine.BaseAddress, 4, 0x1EF8AF8, 0xE9C, 0, 0);
	std::cout << "dwFirstEntity: ";
	std::cout << std::to_string(pEngine.dwFirstEntity) << std::endl;
	//pMemory.Functions.ReadMultiple(&pMemory.Entity, pMemory.dwFirstEntity, );
	//pEngine.Memory.ReadOffset(&pEngine.EntityType, pEngine.dwFirstEntity, 3, 0xC, 0x4, 0xC, 0);
	std::cout << "EntityType: ";
	std::cout << pEngine.EntityType << std::endl;



	for (int i = 0; i < 30; i++)
	{
		//pEngine.Memory.Read(&pEngine.dwFirstEntity, pEngine.dwFirstEntity);
		//pEngine.Memory.ReadOffset(&pEngine.EntityType, pEngine.dwFirstEntity, 3, 0xC, 0x4, 0xC, 0);
		std::cout << "EntityType: ";
		std::cout << pEngine.EntityType << std::endl;
	}*/



	while (pEngine.Thread2Active)
	{
		Sleep(100);
	}
	pEngine.Process.Detach();
	MessageBox(NULL, "Terminated successfully.", "V8Engine Overlay", MB_OK);
	return 0;
}
