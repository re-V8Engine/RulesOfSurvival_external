#include "stdafx.h"

void DirectX::DirectXDrawing::DrawMenu()
{
	int y = (pDirectX.Viewport.Height / 2) - 200;
	pDirectX.Drawing.DrawString(50, y, "Speedhack[Num,]: [" + std::to_string((int)pGlobalVariables.Settings.Speed) + "]", D3DCOLOR_ARGB(255, 255, 255, 255), true, D3DCOLOR_ARGB(255, 0, 0, 0), false);
	y += 15;
	pDirectX.Drawing.DrawString(50, y, "Noclip[Num0]: [" + pGlobalVariables.Settings.NoclipStatus + "]", D3DCOLOR_ARGB(255, 255, 255, 255), true, D3DCOLOR_ARGB(255, 0, 0, 0), false);
	y += 15;
	pDirectX.Drawing.DrawString(50, y, "WalkUnderwater[Num1]: [" + pGlobalVariables.Settings.WalkUnderwaterStatus + "]", D3DCOLOR_ARGB(255, 255, 255, 255), true, D3DCOLOR_ARGB(255, 0, 0, 0), false);
	y += 15;
	pDirectX.Drawing.DrawString(50, y, "Gravity[F10+/F11-]: [" + std::to_string((int)pGlobalVariables.Settings.fGravity) + "]", D3DCOLOR_ARGB(255, 255, 255, 255), true, D3DCOLOR_ARGB(255, 0, 0, 0), false);
	//y += 15;
	//pDirectX.Drawing.DrawString(50, y, "X:" + std::to_string((int)pGlobalVariables.Settings.Origin[0]) + " " + "Y:" + std::to_string((int)pGlobalVariables.Settings.Origin[2]) + " " + "Z:" + std::to_string((int)pGlobalVariables.Settings.Origin[1]), D3DCOLOR_ARGB(255, 255, 255, 255), true, D3DCOLOR_ARGB(255, 0, 0, 0), false);
}

void DirectX::DirectXDrawing::DrawString(float X, float Y, std::string Text, D3DCOLOR TextColor, bool Outlined, D3DCOLOR OutlineColor, bool Centered)
{
	RECT Rect;
	Rect.top = Y;
	Rect.left = X;
	Rect.bottom = Y;
	Rect.right = X;
	if (Outlined)
	{
		RECT OutlineRectTop;
		OutlineRectTop.top = Y - 1.f;
		OutlineRectTop.left = X;
		OutlineRectTop.bottom = Y;
		OutlineRectTop.right = X - 1.f;
		RECT OutlineRectLeft;
		OutlineRectLeft.top = Y;
		OutlineRectLeft.left = X - 1.f;
		OutlineRectLeft.bottom = Y;
		OutlineRectLeft.right = X - 1.f;
		RECT OutlineRectRight;
		OutlineRectRight.top = Y;
		OutlineRectRight.left = X + 1.f;
		OutlineRectRight.bottom = Y;
		OutlineRectRight.right = X + 1.f;
		RECT OutlineRectBottom;
		OutlineRectBottom.top = Y + 1.f;
		OutlineRectBottom.left = X;
		OutlineRectBottom.bottom = Y + 1.f;
		OutlineRectBottom.right = X;
		if (Centered)
		{
			pDirectX.Font->DrawTextA(NULL, Text.c_str(), strlen(Text.c_str()), &OutlineRectTop, DT_CENTER | DT_NOCLIP, OutlineColor);
			pDirectX.Font->DrawTextA(NULL, Text.c_str(), strlen(Text.c_str()), &OutlineRectLeft, DT_CENTER | DT_NOCLIP, OutlineColor);
			pDirectX.Font->DrawTextA(NULL, Text.c_str(), strlen(Text.c_str()), &OutlineRectRight, DT_CENTER | DT_NOCLIP, OutlineColor);
			pDirectX.Font->DrawTextA(NULL, Text.c_str(), strlen(Text.c_str()), &OutlineRectBottom, DT_CENTER | DT_NOCLIP, OutlineColor);
		}
		else
		{
			pDirectX.Font->DrawTextA(NULL, Text.c_str(), strlen(Text.c_str()), &OutlineRectTop, DT_NOCLIP, OutlineColor);
			pDirectX.Font->DrawTextA(NULL, Text.c_str(), strlen(Text.c_str()), &OutlineRectLeft, DT_NOCLIP, OutlineColor);
			pDirectX.Font->DrawTextA(NULL, Text.c_str(), strlen(Text.c_str()), &OutlineRectRight, DT_NOCLIP, OutlineColor);
			pDirectX.Font->DrawTextA(NULL, Text.c_str(), strlen(Text.c_str()), &OutlineRectBottom, DT_NOCLIP, OutlineColor);
		}
	}
	if (Centered)
	{
		pDirectX.Font->DrawTextA(NULL, Text.c_str(), strlen(Text.c_str()), &Rect, DT_CENTER | DT_NOCLIP, TextColor);
	}
	else
	{
		pDirectX.Font->DrawTextA(NULL, Text.c_str(), strlen(Text.c_str()), &Rect, DT_NOCLIP, TextColor);
	}
}

void DirectX::DirectXDrawing::String(char * szString, float X, float Y, int R, int G, int B, int A, bool Centered)
{
	RECT Center = { 0, 0, 0, 0 }, Position = { 0, 0, 0, 0 };

	if (Centered)
		pDirectX.Font->DrawTextA(0, szString, (INT)strlen(szString), &Center, DT_CALCRECT, NULL);

	Position.left = ((LONG)X + 1) - (Center.right / 2);
	Position.top = ((LONG)Y + 1);
	pDirectX.Font->DrawTextA(0, szString, (INT)strlen(szString), &Position, DT_NOCLIP, D3DCOLOR_ARGB(A, 1, 1, 1));

	Position.left = (LONG)X - (Center.right / 2);
	Position.top = (LONG)Y;
	pDirectX.Font->DrawTextA(0, szString, (INT)strlen(szString), &Position, DT_NOCLIP, D3DCOLOR_ARGB(A, R, G, B));
}

void DirectX::DirectXDrawing::DrawCircle(float X, float Y, float Radius, float LineWidth, D3DCOLOR LineColor, bool Outlined, float OutlineWidth, D3DCOLOR OutlineColor)
{
	D3DXVECTOR2 Points[50];
	for (int i = 0; i < 50; i++)
	{
		Points[i] = D3DXVECTOR2(X + (Radius * cos(i)), Y + (Radius * sin(i)));
	}
	if (Outlined)
	{
		pDirectX.Line->SetWidth(LineWidth + OutlineWidth * 2);
		pDirectX.Line->Draw(Points, 50, OutlineColor);
	}
	pDirectX.Line->SetWidth(LineWidth);
	pDirectX.Line->Draw(Points, 50, LineColor);
}

void DirectX::DirectXDrawing::Draw()
{
	//pDirectX.Drawing.DrawString(((FLOAT)pDirectX.Viewport.Width / 2), 75, "Sheit it drawin now...", D3DCOLOR_ARGB(255, 255, 255, 255), true, D3DCOLOR_ARGB(255, 0, 0, 0), true);
	pDirectX.Drawing.String((char*)"[V8Engine Overlay v0.4b]", ((FLOAT)pDirectX.Viewport.Width / 2), 5, 255, 69, 0, 255, true);
	pESP.Functions.DrawCircleCrosshair();
	pDirectX.Drawing.DrawMenu();
	//pESP.Functions.Tick();
}

void DirectX::DirectXDrawing::Render(bool Active)
{
	if (pDirectX.Device)
	{
		pDirectX.Device->Clear(NULL, NULL, D3DCLEAR_TARGET, NULL, 1, NULL);
		pDirectX.Device->BeginScene();
		if (Active)
		{
			pDirectX.Device->GetViewport(&pDirectX.Viewport);

			pDirectX.Drawing.Draw();
		}
		pDirectX.Device->EndScene();
		pDirectX.Device->PresentEx(NULL, NULL, NULL, NULL, NULL);
	}
}

bool DirectX::DirectXFunctions::Setup()
{
	Direct3DCreate9Ex(D3D_SDK_VERSION, &pDirectX.Interface);
	if (pDirectX.Interface)
	{
		ZeroMemory(&pDirectX.Parameters, sizeof(pDirectX.Parameters));
		pDirectX.Parameters.Windowed = TRUE;
		pDirectX.Parameters.SwapEffect = D3DSWAPEFFECT_DISCARD;
		pDirectX.Parameters.hDeviceWindow = pOverlay.Handle;
		pDirectX.Parameters.MultiSampleQuality = D3DMULTISAMPLE_NONE;
		pDirectX.Parameters.BackBufferFormat = D3DFMT_A8R8G8B8;
		pDirectX.Parameters.BackBufferWidth = pOverlay.Width;
		pDirectX.Parameters.BackBufferHeight = pOverlay.Height;
		pDirectX.Parameters.EnableAutoDepthStencil = TRUE;
		pDirectX.Parameters.AutoDepthStencilFormat = D3DFMT_D16;
		pDirectX.Interface->CreateDeviceEx(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, pOverlay.Handle, D3DCREATE_HARDWARE_VERTEXPROCESSING, &pDirectX.Parameters, 0, &pDirectX.Device);
		if (pDirectX.Device)
		{
			D3DXCreateLine(pDirectX.Device, &pDirectX.Line);
			if (pDirectX.Line)
			{
				D3DXCreateFont(pDirectX.Device, 19, NULL, FW_NORMAL, NULL, false, DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, CLEARTYPE_QUALITY, DEFAULT_PITCH, "Calibri", &pDirectX.Font);
				if (pDirectX.Font)
				{
					pDirectX.Line->SetAntialias(TRUE);
					std::cout << "[DirectX] DirectX initialized!" << std::endl;
					return true;
				} 
				else
				{
					MessageBox(NULL, "D3DXCreateFont failed!", "V8Engine Overlay: FATAL ERROR", MB_OK);
				}
			} 
			else
			{
				MessageBox(NULL, "D3DXCreateLine failed!", "V8Engine Overlay: FATAL ERROR", MB_OK);
			}
		} 
		else
		{
			MessageBox(NULL, "CreateDeviceEx failed!", "V8Engine Overlay: FATAL ERROR", MB_OK);
		}
	}
	else
	{
		MessageBox(NULL, "Direct3DCreate9Ex failed!", "V8Engine Overlay: FATAL ERROR", MB_OK);
	}
	return false;
}

void DirectX::DirectXFunctions::Destruct()
{
	pDirectX.Line->Release();
	pDirectX.Font->Release();
	pDirectX.Device->Release();
	pDirectX.Interface->Release();
}