#include "DXUT.h"
#include "TitleScene.h"

void TitleScene::Init()
{
	CAMERA->m_Pos = Vector2(950, 490);
	CAMERA->m_Scale = 1;

	Map = new ScrollMap;
}

void TitleScene::Update()
{
	Map->Update(100);
	if (GetAsyncKeyState(VK_SPACE)) {
		SCENE->ChangeScene("Ingame");
	}
}

void TitleScene::Render()
{
	Map->Render();

	char str[40];
	sprintf(str, "press spacebar to start");
	IMAGE->drawText(str, Vector2(
		50, 90), 40, D3DCOLOR_XRGB(255, 255, 255), false);
}

void TitleScene::Release()
{
	SAFE_DELETE(Map);
}
