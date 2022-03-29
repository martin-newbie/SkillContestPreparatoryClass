#include "DXUT.h"
#include "ObjectManager.h"


ObjectManager::ObjectManager()
{
}


ObjectManager::~ObjectManager()
{
	for (int i = NONE + 1; i < END; i++)
	{
		for (auto iter = ObjList[i].begin(); iter != ObjList[i].end();)
		{
			if ((*iter) == nullptr)
				iter++;
			(*iter)->Release();
			SAFE_DELETE(*iter);
			iter++;
		}
	}
}

void ObjectManager::Update()
{
	for (auto& iter = ColliderList.begin(); iter != ColliderList.end(); iter++)
	{
		CollisionCheck((*iter)->lpGameObject);
	}
	for (int i = NONE; i < END; i++)
	{
		for (auto iter = ObjList[i].begin(); iter != ObjList[i].end();)
		{
			if ((*iter)->CheckDestroy())
			{
				ColliderList.remove((*iter)->collider);
				(*iter)->Release();
				SAFE_DELETE(*iter);
				iter = ObjList[i].erase(iter);
			}
			else if (IsMapOut(*iter))
			{
				ColliderList.remove((*iter)->collider);
				(*iter)->Release();
				SAFE_DELETE(*iter);
				iter = ObjList[i].erase(iter);
			}
			else
			{
				(*iter)->Update();
				iter++;
			}
		}
	}
}

void ObjectManager::Render()
{
	for (int i = 0; i < END; i++)
	{
		for (auto iter : ObjList[i])
			iter->Render();
	}
}

void ObjectManager::Release()
{
	for (int i = 0; i < END; i++)
	{
		for (auto iter : ObjList[i])
			iter->Release();
	}
}

void ObjectManager::CollisionCheck(Object * Object)
{
	for (auto& iter = ColliderList.begin(); iter != ColliderList.end();)
	{
		if ((*iter) == nullptr) { ColliderList.remove((*iter)->lpGameObject->collider);  iter++; }		
		RECT rc2;
		if (IntersectRect(&rc2, &Object->collider->GetRect(), &(*iter)->GetRect()))
		{
			Object->onCollisionStay((*iter)->lpGameObject);
		}
		else
		{
			Object->onCollisionExit((*iter)->lpGameObject);
		}	
		iter++;
	}
}

void ObjectManager::ClearAllObjects()
{
	for (int i = NONE; i < END; i++) {
		for (auto iter : ObjList[i])
		{
			iter->isDestroy = true;
		}
	}
}
