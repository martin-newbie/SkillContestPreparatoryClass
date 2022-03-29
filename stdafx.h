#pragma once
#pragma comment(lib,"legacy_stdio_definitions.lib")

//include
#include <list>
#include <vector>
#include <map>
#include <string>
#include <time.h>

using namespace std;

#define g_device DXUTGetD3D9Device()
#define D_TIME DXUTGetElapsedTime()


const int WINSIZEX = 768;
const int WINSIZEY = 1024;

static bool isWindowed = true;

typedef D3DXVECTOR2 Vector2;
typedef D3DXVECTOR3 Vector3;

//매니저 추가
#include "ImageManager.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "cCameraManager.h"
#include "Timer.h"
