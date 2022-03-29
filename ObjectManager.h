#pragma once
#include "singleton.h"
#include "Object.h"
class ObjectManager :
	public singleton<ObjectManager>
{
	friend class Object;
public:
	ObjectManager();
	virtual ~ObjectManager();

	list<Object*> ObjList[Tag::END];
	list<Collider*> ColliderList;
	int count = 0;

	Object* AddObject(const string& _Key, Object* _obj, Vector2 m_Pos, Tag _objTag)
	{
		count++;
		OutputDebugString(L"오브젝트 생성");
		_obj->Init();
		_obj->m_Tag = _objTag;
		_obj->vPos = m_Pos;
		_obj->m_Key = _Key;
		ObjList[_objTag].emplace_back(_obj);
		return _obj;
	}

	Object* FindObject(const string& _Key)
	{
		for (auto iter1 = 0; iter1 != Tag::END; iter1++)
			for (auto& iter2 : ObjList[iter1])
			{
				if (iter2->m_Key == _Key)
				{
					return iter2;
				}
			}
		return nullptr;
	}

	void AddCollsion(Collider* _collider) { ColliderList.emplace_back(_collider); }

	void Update();
	void Render();
	void Release();
	void CollisionCheck(Object* Object);

	int IsMapOut(Object* obj)
	{
		return (obj->vPos.x < -100
			|| obj->vPos.x  > 868
			|| obj->vPos.y < -300
			|| obj->vPos.y  > 1324);
		
	}
	void ClearAllObjects();


};


#define OBJECT ObjectManager::GetInstace()