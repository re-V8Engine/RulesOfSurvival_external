#include "stdafx.h"

D3DXVECTOR2 ESP::ESPFunctions::WorldToScreen(D3DXVECTOR3 EnemyPosition, LocalPlayer::tDataStructs::tViewMatrix ViewMatrix)
{
	D3DXVECTOR2 ScreenPosition;
	if (ViewMatrix.Matrix)
	{
		ScreenPosition.x = ViewMatrix.Matrix[0][0] * EnemyPosition.x + ViewMatrix.Matrix[0][1] * EnemyPosition.y + ViewMatrix.Matrix[0][2] * EnemyPosition.z + ViewMatrix.Matrix[0][3];
		ScreenPosition.y = ViewMatrix.Matrix[1][0] * EnemyPosition.x + ViewMatrix.Matrix[1][1] * EnemyPosition.y + ViewMatrix.Matrix[1][2] * EnemyPosition.z + ViewMatrix.Matrix[1][3];
		float w = ViewMatrix.Matrix[3][0] * EnemyPosition.x + ViewMatrix.Matrix[3][1] * EnemyPosition.y + ViewMatrix.Matrix[3][2] * EnemyPosition.z + ViewMatrix.Matrix[3][3];
		if (w > 0.01f)
		{
			float invw = 1.0f / w;
			ScreenPosition.x *= invw;
			ScreenPosition.y *= invw;
			float x = pOverlay.Width / 2.f;
			float y = pOverlay.Height / 2.f;
			x += 0.5f * ScreenPosition.x * pOverlay.Width + 0.5f;
			y -= 0.5f * ScreenPosition.y * pOverlay.Height + 0.5f;
			ScreenPosition.x = x + pOverlay.X;
			ScreenPosition.y = y + pOverlay.Y;
		}
		else
		{
			ScreenPosition.x = -1.f;
			ScreenPosition.y = -1.f;
		}
	}
	return ScreenPosition;
}

void ESP::ESPFunctions::DrawCircleCrosshair()
{
	float CenterX = pEngine.Size[0] / 2.f;//pOverlay.Width / 2.f;
	float CenterY = pEngine.Size[1] / 2.f;

	float HeightPixelsPerAngle = pOverlay.Height / 178.f;
	float WidthPixelsPerAngle = pOverlay.Width / 358.f;

	pDirectX.Drawing.DrawCircle(CenterX, CenterY, 10, 0.5f, D3DCOLOR_ARGB(255,255,255,255), true, 0, D3DCOLOR_ARGB(255, 0, 0, 0));
}

void ESP::ESPFunctions::DrawType()
{
	D3DXVECTOR2 BottomPosition = pESP.Functions.WorldToScreen(pESP.PlayerEntityInfo.Origin, pESP.LocalPlayerInfo.ViewMatrix);
	pDirectX.Drawing.DrawString(BottomPosition.x, BottomPosition.y, "1", D3DCOLOR_ARGB(255, 255, 255, 255), true, D3DCOLOR_ARGB(255, 0, 0, 0), false);

}

void ESP::ESPFunctions::Tick()
{
	pEngine.Memory.ReadOffset(&pEngine.dwFirstEntity, pEngine.BaseAddress + 0x20E63D8, 3, 0xE9C, 0, 0);
	pEngine.Memory.ReadOffset(&pEngine.dwLastEntity, pEngine.BaseAddress + 0x20E63D8, 3, 0xE9C, 0, 4);

	while (pEngine.dwFirstEntity != pEngine.dwLastEntity)
	{
		pLocalPlayer.Functions.GetLocalPlayerInfo(&pESP.LocalPlayerInfo);
		pPlayerEntity.Functions.GetPlayerEntityInfo(&pESP.PlayerEntityInfo, pEngine.dwFirstEntity);
		DrawType();
	}
}