#pragma once
#include "Object.h"
class Player :
    public Object
{
    texture* img;
    Timer* AttackTimer;
    bool levelUpChk;

public:
    static int bullet_cnt;
    static float Hp;
    static int Level;

    // Object을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual void onCollisionStay(Object* obj) override;
    virtual void onCollisionExit(Object* obj) override;
};

