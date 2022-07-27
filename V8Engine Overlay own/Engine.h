#include "stdafx.h"

struct Engine
{
	HANDLE ProcessHandle;
	DWORD BaseAddress;
	DWORD dwFirstEntity;
	DWORD dwLastEntity;
	DWORD Entity;
	HWND WinHandle;
	RECT WindowRect;
	int Size[2];
	int Position[2];

	bool Thread1Active;
	bool Thread2Active;

	char EntityType[255];
	
	struct MemoryFunctions
	{
		HANDLE GetProcessHandleByName(std::string ProcessName);
		DWORD CalcBase(std::string ModuleName, HANDLE Process);
		bool IsProcessActive();

		template <typename ReadType> void Read(ReadType* Destination, DWORD Address)
		{
			if (IsProcessActive())
			{
				ReadProcessMemory(pEngine.ProcessHandle, (LPVOID)(Address), Destination, sizeof(ReadType), 0);
			}
		}
		template <typename ReadType> void ReadOffset(ReadType* Destination, DWORD Address, unsigned num, ...)
		{
			va_list args;
			va_start(args, num);
			if (IsProcessActive())
			{
				while (num--)
				{
					Read<DWORD>(&Address, Address);
					Address += va_arg(args, DWORD);
				}
				//Read<DWORD>(&Address, Address);	
				ReadProcessMemory(pEngine.ProcessHandle, (LPVOID)(Address), Destination, sizeof(ReadType), 0);
			}
			va_end(args);
		}
		template <typename WriteType> void Write(WriteType* Data, DWORD Address)
		{
			if (IsProcessActive())
			{
				WriteProcessMemory(pEngine.ProcessHandle, (LPVOID)(Address), Data, sizeof(WriteType), 0);
			}
		}

		template <typename WriteType> void WriteOffset(WriteType* Destination, DWORD Address, unsigned num, ...)
		{
			va_list args;
			va_start(args, num);
			if (IsProcessActive())
			{
				while (num--)
				{
					Read<DWORD>(&Address, Address);
					Address += va_arg(args, DWORD);
				}
				//Read<DWORD>(&Address, Address);	
				WriteProcessMemory(pEngine.ProcessHandle, (LPVOID)(Address), Destination, sizeof(WriteType), 0);
			}
			va_end(args);
		}
	} Memory;

	struct ProcessFunctions 
	{
		D3DCOLOR Color(std::string ColorInfo);
		bool LoadOffsets();

		bool Attach();
		void Detach();
		bool GetSize();
		bool IsWindowActive();
	} Process;


};

extern Engine pEngine;