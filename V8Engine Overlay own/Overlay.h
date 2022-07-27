#include "stdafx.h"

struct Overlay
{
	HWND Handle;
	MSG Message;
	WNDCLASSEX Class;
	RECT Bounds;
	int Width;
	int Height;
	int X;
	int Y;
	struct OverlayFunctions
	{
		static LRESULT CALLBACK WndProc(HWND Handle, UINT Message, WPARAM wParam, LPARAM lParam);
		bool Setup();
		void Refresh();
		void Destruct();
	} Functions;
};

extern Overlay pOverlay;