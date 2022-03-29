#include "DXUT.h"
#include "PlayerBullet.h"

void PlayerBullet::Init()
{
	img = IMAGE->FindImage("Bullet");
	Speed = 1000;

	collider = new Collider;
	collider->lpGameObject = this;
	this->collider->SetRange(64, 64);
	OBJECT->AddCollsion(collider);

	Damage = 15;
}

void PlayerBullet::Update()
{
	this->collider->SetRange(64, 64);

	vPos.y -= Speed * D_TIME;
}

void PlayerBullet::Render()
{
	img->CenterRender(vPos);
}

void PlayerBullet::Release()
{
	SAFE_DELETE(collider);
}

void PlayerBullet::onCollisionStay(Object* obj)
{
	switch (obj->m_Tag)
	{
	case ENEMY:
		isDestroy = true;
		break;
	case BOSS:
		isDestroy = true;
		break;
	}
}

void PlayerBullet::onCollisionExit(Object* obj)
{
}
