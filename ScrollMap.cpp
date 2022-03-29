#include "DXUT.h"
#include "ScrollMap.h"

ScrollMap::ScrollMap()
	:scroll(0)
{
	bg = IMAGE->FindImage("Background");
}

ScrollMap::~ScrollMap()
{
}

void ScrollMap::Update(float speed)
{
	scroll -= speed * D_TIME;
}

void ScrollMap::Render()
{
	float BgSpeed = (int)scroll % bg->info.Height;
	bg->CenterRender(Vector2(WINSIZEX / 2, WINSIZEY / 2 - BgSpeed + bg->info.Height));
	bg->CenterRender(Vector2(WINSIZEX / 2, WINSIZEY / 2 - BgSpeed));
}