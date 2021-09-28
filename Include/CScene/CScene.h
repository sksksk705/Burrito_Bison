#pragma once
#include "../Game.h"
class CScene
{
protected:
	friend class CSceneManager;

protected:
	CScene();
	virtual ~CScene() = 0;

protected:
	list <class CLayer*>	m_LayerList;

private:
	static unordered_map<string, class CObj*>	m_mapPrototype;

public:
	static class CObj* FindPrototype(const string& strKey);

public:
	static void ErasePrototype();
	static void ErasePrototype(const string& strTag);

public:
	class CLayer* CreateLayer(const string& strTag, int iZOrder = 0);
	class CLayer* FindLayer(const string& strTag);


public:
	virtual bool Init();
	virtual void Input(float fDeltaTime);
	virtual void Update(float fDeltaTime);
	virtual void LateUpdate(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Render(HDC hDC, float fDeltaTime);

public:
	static bool LayerSort(class CLayer* pL1, class CLayer* pL2);

public:
	template<typename T>
	static T* CreatePrototype(const string& strTag)
	{
		T* pObj = new T;

		pObj->SetTag(strTag);

		if (!pObj->Init())
		{
			SAFE_RELEASE(pObj);
			return NULL;
		}

		pObj->AddRef();
		m_mapPrototype.insert(make_pair(strTag, pObj));

		return pObj;
	}

};

