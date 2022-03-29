#include "DXUT.h"
#include "MainGame.h"
#include "IngameScene.h"
#include "TitleScene.h"
#include "GameOverScene.h"


MainGame::MainGame()
{
}


MainGame::~MainGame()
{
	Release();
}

void MainGame::Init()
{
	SCENE->AddScene("Title", new TitleScene);
	SCENE->AddScene("Ingame", new IngameScene);
	SCENE->AddScene("GameOver", new GameOverScene);
	SCENE->ChangeScene("Title");
}

void MainGame::Update()
{
	SCENE->Update();
	OBJECT->Update();
	CAMERA->Update();
}

void MainGame::Render()
{
	IMAGE->Begin();

	SCENE->Render();
	OBJECT->Render();
	CAMERA->Render();

	IMAGE->End();
}

void MainGame::Release()
{
	SceneManager::ReleaseInstace();
	ImageManager::ReleaseInstace();
	ObjectManager::ReleaseInstace();
	cCameraManager::ReleaseInstace();
}

void MainGame::LostDevice()
{
	IMAGE->LostDevice();
}

void MainGame::ResetDevice()
{
	IMAGE->ResetDevice();
}
