#pragma once
#include "../Game.h"

class CSceneManager
{
private:
	 class CScene* m_pScene;
	 class CScene* m_pNextScene;

public:
	bool Init();
	class CScene* GetScene() const { return m_pScene; }

public:
	void Input(float fDeltaTime);
	void Update(float fDeltaTime);
	void LateUpdate(float fDeltaTime);
	void Collision(float fDeltaTime);
	void Render(HDC hDC, float fDeltaTime);

public:
	template<typename T>
	T* CreateScene(SCENE_CREATE sc = SC_CURRENT)
	{
		T* pScene = new T;

		if (!pScene->Init())
		{
			SAFE_DELETE(pScene);
			return NULL;
		}

		switch (sc)
		{
		case SC_CURRENT:
			SAFE_DELETE(m_pScene);
			m_pScene = pScene;
			break;
		case SC_NEXT:
			SAFE_DELETE(m_pNextScene);
			m_pNextScene = pScene;
		}

		return pScene;
	}

	DECLARE_SINGLE(CSceneManager)

};

