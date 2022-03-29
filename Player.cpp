#include "DXUT.h"
#include "Player.h"
#include "PlayerBullet.h"
#include "IngameScene.h"

int Player::bullet_cnt = 1000;
float Player::Hp = 100;
int Player::Level = 1;

void Player::Init()
{
	img = IMAGE->FindImage("Character");
	Speed = 500;
	AttackTimer = new Timer;
	AttackTimer->setTimer(0.2f);
	levelUpChk = true;

	collider = new Collider;
	collider->lpGameObject = this;
	this->collider->SetRange(144,104);
	OBJECT->AddCollsion(collider);
}

void Player::Update()
{
	this->collider->SetRange(144, 104);

	if (Hp > 100) {
		Hp = 100;
	}
	if (Hp <= 0) {
		Hp = 0;
	}

	if (IngameScene::score % 360 == 0 && IngameScene::score != 0) {
		levelUpChk = false;
	}
	if (IngameScene::score >= 360 && !levelUpChk) {
		Level++;
		levelUpChk = true;
		IngameScene::score += 30;
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		vPos.x -= Speed * D_TIME;
		if (vPos.x <= 0)
		{
			vPos.x += Speed * D_TIME;
		}
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		vPos.x += Speed * D_TIME;
		if (vPos.x >= WINSIZEX)
		{
			vPos.x -= Speed * D_TIME;
		}
	}
	if (GetAsyncKeyState(VK_UP))
	{
		vPos.y -= Speed * D_TIME;
		if (vPos.y <= 0)
		{
			vPos.y += Speed * D_TIME;
		}
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		vPos.y += Speed * D_TIME;
		if (vPos.y >= WINSIZEY)
		{
			vPos.y -= Speed * D_TIME;
		}
	}

	if (GetAsyncKeyState('A'))
	{
		if (AttackTimer->Update() && bullet_cnt != 0)
		{
			OBJECT->AddObject("PlayerBullet", new PlayerBullet, vPos, BULLET);
			bullet_cnt--;
		}
	}
	if (Hp <= 0)
	{
		SCENE->ChangeScene("GameOver");

	}
}

void Player::Render()
{
	img->CenterRender(vPos, D3DXToRadian(0), Vector2(4, 4), D3DCOLOR_ARGB(255, 255, 255, 255));
}

void Player::Release()
{
	SAFE_DELETE(AttackTimer);
	SAFE_DELETE(collider);
}

void Player::onCollisionStay(Object* obj)
{
	switch (obj->m_Tag)
	{
	case EBULLET:
		Hp -= obj->Damage;
		break;
	case AMMO:
		bullet_cnt += 10;
		break;
	case ENEMY:
		Hp -= 30;
		obj->isDestroy = true;
		CAMERA->Shake(10, 1);
		break;
	case MISSILES:
		Hp -= 60;
		obj->isDestroy = true;
		CAMERA->Shake(10, 1);
		break;
	}
}

void Player::onCollisionExit(Object* obj)
{
}


