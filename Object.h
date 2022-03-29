#pragma once
#include "Collider.h"



enum ObjectTag :char
{
	NONE,
	EBULLET,
	BULLET,
	ENEMY,
	AMMO,
	PLAYER,
	MISSILES,
	BOSS,
	END,
}typedef Tag;

class Object
{
public:
	Object();
	virtual ~Object();

	Vector2 vPos;
	Collider* collider;
	Tag m_Tag;
	string m_Key;
	
	float Damage;
	float Hp;
	float Speed;

	bool isDestroy = false;

	virtual void Init() PURE;
	virtual void Update() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;
	virtual void onCollisionStay(Object* obj) PURE;
	virtual void onCollisionExit(Object* obj) PURE;

	bool CheckDestroy() { return isDestroy; }
};

