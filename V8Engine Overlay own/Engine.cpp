#include "stdafx.h"

HANDLE Engine::MemoryFunctions::GetProcessHandleByName(std::string ProcessName)
{
	PROCESSENTRY32 ProcessEntry;
	ProcessEntry.dwSize = sizeof(ProcessEntry);
	HANDLE HandleSnaphot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	if (Process32First(HandleSnaphot, &ProcessEntry) == TRUE)
	{
		if (!strcmp(ProcessEntry.szExeFile, ProcessName.c_str()))
		{
			HANDLE ProcessHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, ProcessEntry.th32ProcessID);
			return ProcessHandle;
		}
		else
		{
			while (Process32Next(HandleSnaphot, &ProcessEntry) == TRUE)
			{
				if (!strcmp(ProcessEntry.szExeFile, ProcessName.c_str()))
				{
					HANDLE ProcessHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, ProcessEntry.th32ProcessID);
					return ProcessHandle;
				}
			}
		}
	}
	CloseHandle(HandleSnaphot);
	return { 0 };
}

DWORD Engine::MemoryFunctions::CalcBase(std::string ModuleName, HANDLE Process)
{
	MODULEENTRY32 ModuleEntry;
	ModuleEntry.dwSize = sizeof(MODULEENTRY32);
	HANDLE SnapHandle = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, GetProcessId(Process));
	if (Module32First(SnapHandle, &ModuleEntry) == TRUE)
	{
		if (!_stricmp(ModuleEntry.szModule, ModuleName.c_str()))
		{
			DWORD ModuleAddress = (DWORD)ModuleEntry.modBaseAddr;
			return ModuleAddress;
		}
		else
		{
			while (Module32Next(SnapHandle, &ModuleEntry) == TRUE)
			{
				if (!_stricmp(ModuleEntry.szModule, ModuleName.c_str()))
				{
					DWORD ModuleAddress = (DWORD)ModuleEntry.modBaseAddr;
					return ModuleAddress;
				}
			}
		}
	}
	CloseHandle(SnapHandle);
	return{ 0 };
}

D3DCOLOR Engine::ProcessFunctions::Color(std::string ColorInfo)
{
	int a, r, g, b;
	a = std::stoi(ColorInfo.substr(0, 3));
	r = std::stoi(ColorInfo.substr(3, 3));
	g = std::stoi(ColorInfo.substr(6, 3));
	b = std::stoi(ColorInfo.substr(9, 3));
	return D3DCOLOR_ARGB(a, r, g, b);
}

bool Engine::ProcessFunctions::LoadOffsets()
{
	pGlobalVariables.Offsets.Client = 0x0;
	return true;
}

bool Engine::ProcessFunctions::Attach()
{
	pEngine.ProcessHandle = pEngine.Memory.GetProcessHandleByName(pGlobalVariables.Settings.TagetName);
	if (pEngine.ProcessHandle)
	{
		pEngine.WinHandle = FindWindow(NULL, pGlobalVariables.Settings.TargetWindowName.c_str());
		pEngine.BaseAddress = pEngine.Memory.CalcBase(pGlobalVariables.Settings.TagetName, pEngine.ProcessHandle);
		if (pEngine.BaseAddress)
		{
			std::cout << "[Process] Game found and attached!" << std::endl;
			return true;
		}
	}
	return false;
}

bool Engine::MemoryFunctions::IsProcessActive()
{
	DWORD ExitCode;
	GetExitCodeProcess(pEngine.ProcessHandle, &ExitCode);
	if (ExitCode == STILL_ACTIVE)
	{
		return true;
	}
	return false;
}

void Engine::ProcessFunctions::Detach()
{
	if (pEngine.ProcessHandle)
	{
		CloseHandle(pEngine.ProcessHandle);
	}
}

bool Engine::ProcessFunctions::GetSize()
{
	if (!GetWindowRect(pEngine.WinHandle, &pEngine.WindowRect))
		exit(1);
	pEngine.Size[0] = (pEngine.WindowRect.right - pEngine.WindowRect.left);
	pEngine.Size[1] = (pEngine.WindowRect.bottom - pEngine.WindowRect.top) + 23;

	pEngine.Position[0] = pEngine.WindowRect.left;
	pEngine.Position[0] = pEngine.WindowRect.top;

	return true;
}

bool Engine::ProcessFunctions::IsWindowActive()
{
	HWND ActiveWindow = GetForegroundWindow();

	if (ActiveWindow != pEngine.WinHandle)
	{
		return false;
	}
	return true;
}