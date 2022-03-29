#pragma once
class ScrollMap
{
public:
	ScrollMap();
	~ScrollMap();

	texture* bg;
	float scroll;
	void Update(float speed);
	void Render();
};