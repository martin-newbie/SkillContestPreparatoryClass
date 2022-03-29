#include "DXUT.h"
#include "Enemy.h"
#include "EnemyBullet.h"
#include "IngameScene.h"
#include "Boss.h"
#include "Player.h"

void Enemy::Init()
{
	img = IMAGE->FindImage("Enemy");
	Speed = 300;

	AttackTimer = new Timer;
	AttackTimer->setTimer(0.6f);

	collider = new Collider;
	collider->lpGameObject = this;
	this->collider->SetRange(144, 104);
	OBJECT->AddCollsion(collider);

	Hp = 30;
}

void Enemy::Update()
{
	this->collider->SetRange(144, 104);

	vPos.y += Speed * D_TIME;

	if (Hp <= 0)
	{
		isDestroy = true;
		IngameScene::score += 30;
		Player::Hp += 20;
	}

	if (AttackTimer->Update())
	{
		OBJECT->AddObject("EnemyBullet", new EnemyBullet(Vector2(0.5, 1)), vPos, EBULLET);
		OBJECT->AddObject("EnemyBullet", new EnemyBullet(Vector2(-0.5, 1)), vPos, EBULLET);
	}
}

void Enemy::Render()
{
	img->CenterRender(vPos, D3DXToRadian(180), Vector2(4,4),D3DCOLOR_ARGB(255,255,255,255));
}

void Enemy::Release()
{
	SAFE_DELETE(AttackTimer);
	SAFE_DELETE(collider);
}

void Enemy::onCollisionStay(Object* obj)
{
	switch (obj->m_Tag)
	{
	case BULLET:
		Hp -= obj->Damage;
		break;
	}
}

void Enemy::onCollisionExit(Object* obj)
{
}
