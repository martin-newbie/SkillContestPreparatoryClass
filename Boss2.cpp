#include "DXUT.h"
#include "Boss2.h"
#include "Player.h"
#include "IngameScene.h"
#include "EnemyBullet.h"

void Boss2::Init()
{
	img = IMAGE->FindImage("Boss2");

	AttackTimer = new Timer;
	AttackTimer->setTimer(0.6f);

	collider = new Collider;
	collider->lpGameObject = this;
	this->collider->SetRange(897, 554);
	OBJECT->AddCollsion(collider);

	Hp = 100 * Player::Level;
}

void Boss2::Update()
{
	this->collider->SetRange(144, 104);
	if (Hp <= 0)
	{
		IngameScene::score += 30;
		Player::Hp += 50;
		isDestroy = true;
	}

	if (AttackTimer->Update())
	{
		for (int i = 0; i < 4; i++)
		{
			OBJECT->AddObject("EnemyBullet", new EnemyBullet(Vector2(-i - 0.5, 1)), vPos, EBULLET);
			OBJECT->AddObject("EnemyBullet", new EnemyBullet(Vector2(i + 0.5, 1)), vPos, EBULLET);

		}
		OBJECT->AddObject("EnemyBullet", new EnemyBullet(Vector2(0, 2)), vPos, EBULLET);
		OBJECT->AddObject("EnemyBullet", new EnemyBullet(Vector2(0, -1)), vPos, EBULLET);
	}
}

void Boss2::Render()
{
	img->CenterRender(vPos, D3DXToRadian(0), Vector2(10, 10), D3DCOLOR_ARGB(255, 255, 255, 255));
}

void Boss2::Release()
{
	SAFE_DELETE(AttackTimer);
	SAFE_DELETE(collider);
}

void Boss2::onCollisionStay(Object* obj)
{
	switch (obj->m_Tag)
	{
	case BULLET:
		Hp -= obj->Damage;
		break;
	}
}

void Boss2::onCollisionExit(Object* obj)
{
}
