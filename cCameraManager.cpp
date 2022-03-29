#include "DXUT.h"
#include "cCameraManager.h"


cCameraManager::cCameraManager()
{
}


cCameraManager::~cCameraManager()
{
}

void cCameraManager::Init()
{
	m_ShakePos = Vector2(0, 0);
	m_ShakeForce = 0;
	m_Scale = 1;
}

void cCameraManager::Update()
{
	if (m_ShakeForce != 0)
	{
		m_ShakeForce -= m_ShakeTime * D_TIME;
		if (m_ShakeForce <= 0)
		{
			m_ShakeForce = 0;
			m_ShakePos = Vector2(0, 0);
		}
		else
		{
			m_ShakePos = Vector2(Random(-m_ShakeForce, m_ShakeForce), Random(-m_ShakeForce, m_ShakeForce));
		}
	}
	D3DXMATRIX p, s;
	D3DXMatrixTranslation(&p, -m_Pos.x + 960 / m_Scale + m_ShakePos.x, -m_Pos.y + 540 / m_Scale + m_ShakePos.y, 0);
	D3DXMatrixScaling(&s, m_Scale, m_Scale, 1);
	m_Mat = p * s;
	D3DXMatrixInverse(&m_InversedMat, NULL, &m_Mat);
}

void cCameraManager::Render()
{
	g_device->SetTransform(D3DTS_VIEW, &m_Mat);
}

void cCameraManager::Release()
{
}

void cCameraManager::Shake(float _Force, float _Time)
{
	m_ShakeForce = _Force;
	m_ShakeTime = _Force / _Time;
}

float cCameraManager::Random(float _Min, float _Max)
{
	return _Min + ((rand() | (rand() << 16)) % (int)(_Max * 10000 - _Min * 10000 + 1)) * 0.0001;
}
