#pragma once
#include "Object.h"
class Boss2 :
    public Object
{
    texture* img;
    Timer* AttackTimer;
    // Object��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual void onCollisionStay(Object* obj) override;
    virtual void onCollisionExit(Object* obj) override;
};

