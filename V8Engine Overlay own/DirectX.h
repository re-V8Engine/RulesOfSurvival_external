#include "stdafx.h"

struct DirectX
{
	IDirect3D9Ex* Interface;
	IDirect3DDevice9Ex* Device;
	D3DPRESENT_PARAMETERS Parameters;
	ID3DXLine* Line;
	ID3DXFont* Font;
	D3DVIEWPORT9 Viewport;

	struct DirectXFunctions
	{
		bool Setup();
		void Destruct();
	} Functions;

	struct DirectXDrawing
	{
		void DrawMenu();
		void DrawCircle(float X, float Y, float Radius, float LineWidth, D3DCOLOR LineColor, bool Outlined, float OutlineWidth, D3DCOLOR OutlineColor);
		void DrawString(float X, float Y, std::string Text, D3DCOLOR TextColor, bool Outlined, D3DCOLOR OutlineColor, bool Centered);
		void String(char * szString, float X, float Y, int R, int G, int B, int A, bool Centered);
		void Render(bool Active);
		void Draw();
	} Drawing;
};

extern DirectX pDirectX;