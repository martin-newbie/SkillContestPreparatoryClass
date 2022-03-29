#include "DXUT.h"
#include "EnemyBullet.h"

EnemyBullet::EnemyBullet()
{
}

EnemyBullet::EnemyBullet(Vector2 dir)
	:dir(dir)
{
}

EnemyBullet::~EnemyBullet()
{
}

void EnemyBullet::Init()
{
	img = IMAGE->FindImage("Bullet");
	Speed = 700;

	collider = new Collider;
	collider->lpGameObject = this;
	this->collider->SetRange(64, 64);
	OBJECT->AddCollsion(collider);

	Damage = 10;
}

void EnemyBullet::Update()
{
	this->collider->SetRange(10, 10);

	vPos += dir * Speed * D_TIME;
}

void EnemyBullet::Render()
{
	img->CenterRender(vPos, D3DXToRadian(180), Vector2(1, 1), D3DCOLOR_XRGB(255, 0, 0));
}

void EnemyBullet::Release()
{
	SAFE_DELETE(collider);
}

void EnemyBullet::onCollisionStay(Object* obj)
{
	switch (obj->m_Tag)
	{
	case PLAYER:
		CAMERA->Shake(10, 1);
		isDestroy = true;
		break;
	}
}

void EnemyBullet::onCollisionExit(Object* obj)
{
}
