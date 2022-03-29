#pragma once
#include "Object.h"
class Object;

class Collider :
	public RECT
{
public:
	Collider();
	virtual ~Collider();

	Object* lpGameObject = nullptr;

	void Init();
	void SetRange(float width, float height);

	Vector2 Pos;

	RECT GetRect()
	{
		RECT rt;


		rt.left = left;
		rt.right = right;
		rt.top = top;
		rt.bottom = bottom;
		return rt;
	}
};

