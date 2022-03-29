#include "DXUT.h"
#include "Collider.h"


Collider::Collider()
{
}


Collider::~Collider()
{
}

void Collider::Init()
{

}

void Collider::SetRange(float width, float height)
{
	left = lpGameObject->vPos.x - width / 2;
	right = lpGameObject->vPos.x + width / 2;
	top = lpGameObject->vPos.y - height / 2;
	bottom = lpGameObject->vPos.y + height / 2;
}
