#pragma once
#include "Scene.h"
#include "ScrollMap.h"
class GameOverScene :
    public Scene
{
    ScrollMap* Map;
    // Scene��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};
