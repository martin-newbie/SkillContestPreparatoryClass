#include "DXUT.h"
#include "GameOverScene.h"

void GameOverScene::Init()
{
	CAMERA->m_Pos = Vector2(950, 490);
	CAMERA->m_Scale = 1;

	Map = new ScrollMap;
}

void GameOverScene::Update()
{
	Map->Update(100);

	if (GetAsyncKeyState(VK_SPACE)) {
		PostQuitMessage(0);

	}
}

void GameOverScene::Render()
{
	Map->Render();

	char str[40];
	sprintf(str, "Game over");
	IMAGE->drawText(str, Vector2(50, 40), 40, D3DCOLOR_XRGB(255, 255, 0, 0), false);
	sprintf(str, "press spacebar to end");
	IMAGE->drawText(str, Vector2(
		50, 90), 40, D3DCOLOR_XRGB(255, 255, 255), false);
}

void GameOverScene::Release()
{
	SAFE_DELETE(Map);
}
