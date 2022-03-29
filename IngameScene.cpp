#include "DXUT.h"
#include "IngameScene.h"
#include "Player.h"
#include "Enemy.h"
#include "Ammo.h"
#include "Player.h"
#include "Boss.h"
#include "Boss2.h"
#include "Missiles.h"


int IngameScene::score = 0;

void IngameScene::Init()
{
	OBJECT->AddObject("Player", new Player, Vector2(WINSIZEX / 2, WINSIZEY / 2), PLAYER);
	Map = new ScrollMap;

	EnemySpawn = new Timer;
	AmmoSpawn = new Timer;
	EnemySpawnTimer = new Timer;
	MissilesSpawnTimer = new Timer;
	EnemySpawnTimer->setTimer(0.03f);
	EnemySpawn->setTimer(3.f);
	AmmoSpawn->setTimer(10.f);
	MissilesSpawnTimer->setTimer(15.0f);
	srand(time(NULL));
	CAMERA->m_Pos = Vector2(950, 490);
	CAMERA->m_Scale = 1;
	//CAMERA->Shake(10, 1);
	boss1 = false;
	boss2 = false;
}

void IngameScene::Update()
{
	Map->Update(100);

	if (EnemySpawn->Update())
	{
		for (int i = 0; i < Player::Level; i++)
		{
			float randx = (rand() % 600) + 100;
			OBJECT->AddObject("Enemy", new Enemy, Vector2(randx, -80), ENEMY);
		}
	}
	/*if (score >= 1000) {
		
	}*/
	if (MissilesSpawnTimer->Update()) 
	{
		for (int i = 0; i < Player::Level; i++)
		{
			float randx = (rand() % 600) + 100;
			OBJECT->AddObject("Missiles", new Missiles, Vector2(randx, -80), MISSILES);
		}
	}
	

	if (AmmoSpawn->Update())
	{
		float randx = (rand() % 600) + 100;
		OBJECT->AddObject("Ammo", new Ammo, Vector2(randx, -80), AMMO);
	}
	if (Player::Level == 2 && !boss1) {
		boss1 = true;
		
		auto player = OBJECT->ObjList[PLAYER].front();
		Vector2 playerPos = player->vPos;

		OBJECT->AddObject("Boss1", new Boss, Vector2(400, 100), BOSS);
	}
	if (Player::Level == 3 && !boss2 && boss1) {
		boss2 = true;
		auto player = OBJECT->ObjList[PLAYER].front();
		Vector2 playerPos = player->vPos;
		OBJECT->AddObject("Boss2", new Boss2, Vector2(400, 100), BOSS);
	}
	//if(Player::Level == 4 && boss1 && boss2 && !boss3)

}

void IngameScene::Render()
{
	Map->Render();
	
	char str[20];
	sprintf(str, "score : %d", score);
	IMAGE->drawText(str, Vector2(0, 0), 40, D3DCOLOR_XRGB(255, 255, 255), false);

	int temp = Player::bullet_cnt;
	sprintf(str, "ammo : %d", temp);
	IMAGE->drawText(str, Vector2(0, 50), 40, D3DCOLOR_XRGB(255, 255, 255), false);

	sprintf(str, "Hp : %f", Player::Hp);
	IMAGE->drawText(str, Vector2(0, 100), 40, D3DCOLOR_XRGB(255, 255, 255), false);

	sprintf(str, "Level : %d", Player::Level);
	IMAGE->drawText(str, Vector2(0, 150), 40, D3DCOLOR_XRGB(255, 255, 255), false);

}

void IngameScene::Release()
{
	SAFE_DELETE(Map);
	SAFE_DELETE(EnemySpawn);
	SAFE_DELETE(EnemySpawnTimer);
	SAFE_DELETE(MissilesSpawnTimer);
	SAFE_DELETE(AmmoSpawn);
}
