#pragma once
#include "singleton.h"
class cCameraManager : public singleton<cCameraManager>
{
public:
	cCameraManager();
	~cCameraManager();

	void Init();
	void Update();
	void Render();
	void Release();

	D3DXMATRIX m_Mat;
	D3DXMATRIX m_InversedMat;
	Vector2 m_Pos;
	Vector2 m_ShakePos;
	float m_ShakeForce;
	float m_ShakeTime;
	float m_Scale;

	void Shake(float _Force, float _Time);
	float Random(float _Min, float _Max);
};

#define CAMERA cCameraManager::GetInstace()