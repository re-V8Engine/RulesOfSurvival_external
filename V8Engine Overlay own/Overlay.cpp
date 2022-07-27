#include "stdafx.h"

LRESULT CALLBACK Overlay::OverlayFunctions::WndProc(HWND Handle, UINT Message, WPARAM wParam, LPARAM lParam)
{
	switch (Message)
	{
	case WM_PAINT:
		pEngine.Process.GetSize();
		MoveWindow(pEngine.WinHandle, pEngine.Position[0], pEngine.Position[1], pEngine.Size[0], pEngine.Size[1], false);
		pDirectX.Drawing.Render(pEngine.Process.IsWindowActive());
	case WM_ERASEBKGND:
		return 0;

	default:
		return DefWindowProc(Handle, Message, wParam, lParam);
	}
}

bool Overlay::OverlayFunctions::Setup()
{
	ZeroMemory(&pOverlay.Class, sizeof(pOverlay.Class));
	pOverlay.Class.cbSize = sizeof(pOverlay.Class);
	pOverlay.Class.hInstance = GetModuleHandle(NULL);
	pOverlay.Class.lpfnWndProc = pOverlay.Functions.WndProc;
	pOverlay.Class.lpszClassName = "V8Engine Overlay v0.4b";
	pOverlay.Class.style = CS_HREDRAW | CS_VREDRAW;
	pOverlay.Class.hbrBackground = CreateSolidBrush(RGB(0, 0, 0));

	if (RegisterClassEx(&pOverlay.Class))
	{
		pOverlay.Handle = CreateWindowEx(WS_EX_TOPMOST | WS_EX_TRANSPARENT | WS_EX_LAYERED, pOverlay.Class.lpszClassName, pOverlay.Class.lpszClassName, WS_POPUP, pOverlay.X, pOverlay.Y, pOverlay.Width, pOverlay.Height, NULL, NULL, pOverlay.Class.hInstance, NULL);
		if (pOverlay.Handle)
		{
			SetLayeredWindowAttributes(pOverlay.Handle, RGB(0, 0, 0), 255, LWA_COLORKEY | LWA_ALPHA);
			ShowWindow(pOverlay.Handle, 1);
			MARGINS Margin = { -1, -1, -1, -1 };
			DwmExtendFrameIntoClientArea(pOverlay.Handle, &Margin);
			HWND WinHandle = FindWindow(NULL, pGlobalVariables.Settings.TargetWindowName.c_str());
			if (WinHandle)
			{
				if (IsWindowVisible(WinHandle))
				{
					GetClientRect(WinHandle, &pOverlay.Bounds);
					pOverlay.Width = pOverlay.Bounds.right - pOverlay.Bounds.left;
					pOverlay.Height = pOverlay.Bounds.bottom - pOverlay.Bounds.top;
					ZeroMemory(&pOverlay.Bounds, sizeof(pOverlay.Bounds));
					GetWindowRect(WinHandle, &pOverlay.Bounds);
					pOverlay.X = pOverlay.Bounds.left;
					pOverlay.Y = pOverlay.Bounds.top;
					SetWindowPos(pOverlay.Handle, HWND_TOPMOST, pOverlay.X, pOverlay.Y, pOverlay.Width, pOverlay.Height, NULL);
					return true;
				}
			}
			
		}
	}
	return false;
}

void Overlay::OverlayFunctions::Refresh()
{
	if (pOverlay.Handle)
	{
		InvalidateRect(pOverlay.Handle, NULL, false);
		if (PeekMessage(&pOverlay.Message, pOverlay.Handle, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&pOverlay.Message);
			DispatchMessage(&pOverlay.Message);
		}
	}
	else
	{
		if (pOverlay.Functions.Setup())
		{
			std::cout << "[Overlay] Overlay created!" << std::endl;
			if (!pDirectX.Functions.Setup())
			{
				MessageBox(NULL, "Failed to initialize DirectX!", "V8Engine Overlay: FATAL ERROR", MB_OK);
				exit(1);
			} 
		}
		else
		{
			MessageBox(NULL, "Failed to create overlay window!", "V8Engine Overlay: FATAL ERROR", MB_OK);
			exit(1);
		}
	}
}

void Overlay::OverlayFunctions::Destruct()
{
	DestroyWindow(pOverlay.Handle);
	UnregisterClass(pOverlay.Class.lpszClassName, pOverlay.Class.hInstance);
}