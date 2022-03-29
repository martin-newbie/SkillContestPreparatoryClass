#pragma once
#include "Scene.h"
#include "ScrollMap.h"

class IngameScene :
    public Scene
{
    ScrollMap* Map;
    Timer* EnemySpawn;
    Timer* AmmoSpawn;
    Timer* EnemySpawnTimer;
    Timer* MissilesSpawnTimer;
    bool boss1;
    bool boss2;
public:
    static int score;
    

    // Scene을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};