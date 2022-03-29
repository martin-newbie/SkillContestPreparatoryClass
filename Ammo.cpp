#include "DXUT.h"
#include "Ammo.h"

void Ammo::Init()
{
	AmmoImg = IMAGE->FindImage("Ammo");
	collider = new Collider;
	collider->lpGameObject = this;
	collider->SetRange(10, 10);
	OBJECT->AddCollsion(collider);
}

void Ammo::Update()
{
	collider->SetRange(10, 10);
	vPos.y += 30;
}

void Ammo::Render()
{
	AmmoImg->CenterRender(vPos);
}

void Ammo::Release()
{
	SAFE_DELETE(collider);
}

void Ammo::onCollisionStay(Object* obj)
{
	switch (obj->m_Tag)
	{
	case PLAYER:
		isDestroy = true;
		break;
	default:
		break;
	}
}

void Ammo::onCollisionExit(Object* obj)
{
}
