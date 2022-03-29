#include "DXUT.h"
#include "Missiles.h"
#include "IngameScene.h"
#include "Player.h"

void Missiles::Init()
{
	img = IMAGE->FindImage("Missiles");
	Speed = 600;


	collider = new Collider;
	collider->lpGameObject = this;
	this->collider->SetRange(144, 104);
	OBJECT->AddCollsion(collider);

	Hp = 45;
}

void Missiles::Update()
{
	this->collider->SetRange(144, 104);

	vPos.y += Speed * D_TIME;
	if (Hp <= 0)
	{
		isDestroy = true;
		IngameScene::score += 30;
		Player::Hp += 5;
	}
}

void Missiles::Render()
{
	img->CenterRender(vPos, D3DXToRadian(0), Vector2(4, 4), D3DCOLOR_ARGB(255, 255, 255, 255));
}

void Missiles::Release()
{
	SAFE_DELETE(collider);
}

void Missiles::onCollisionStay(Object* obj)
{
	switch (obj->m_Tag)
	{
	case BULLET:
		Hp -= obj->Damage;
		break;
	}
}

void Missiles::onCollisionExit(Object* obj)
{
}
