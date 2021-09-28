#include "CScene.h"
#include "CSceneManager.h"
#include "CLayer.h"
#include "../Obj/CObj.h"

unordered_map<string, CObj*> CScene::m_mapPrototype;

CScene::CScene()
{
	CLayer* pLayer = CreateLayer("Default",1);
	pLayer = CreateLayer("UI", INT_MAX);
	pLayer = CreateLayer("Stage");
}

CScene::~CScene()
{
	Safe_Delete_VecList(m_LayerList);
	ErasePrototype();
}

CObj* CScene::FindPrototype(const string& strKey)
{
	unordered_map<string, CObj*>::iterator  iter = m_mapPrototype.find(strKey);

	if (iter == m_mapPrototype.end())
		return NULL;
	return iter->second;
}

void CScene::ErasePrototype()
{
	Safe_Release_Map(m_mapPrototype);
}

void CScene::ErasePrototype(const string& strTag)
{
	unordered_map<string, CObj*>::iterator  iter = m_mapPrototype.find(strTag);

	if (!iter->second)
		return;

	SAFE_RELEASE(iter->second);
	m_mapPrototype.erase(iter);
}

CLayer* CScene::CreateLayer(const string& strTag, int iZOrder)
{
	CLayer* pLayer = new CLayer;

	pLayer->SetTag( strTag);
	pLayer->SetOrder(iZOrder);
	pLayer->SetScene(this);

	m_LayerList.push_back(pLayer);

	if (m_LayerList.size() >= 2)
		m_LayerList.sort(CScene::LayerSort);

	return pLayer;
}

CLayer* CScene::FindLayer(const string& strTag)
{
	list <CLayer*>::iterator iter;
	list <CLayer*>::iterator iterEnd = m_LayerList.end();
	for (iter = m_LayerList.begin(); iter != iterEnd; ++iter)
	{
		if ((*iter)->GetTag() == strTag)
		{
			return *iter;
		}
	}
	return NULL;
}

bool CScene::Init()
{
	return true;
}

void CScene::Input(float fDeltaTime)
{
	list <CLayer*>::iterator iter;
	list <CLayer*>::iterator iterEnd = m_LayerList.end();

	for (iter = m_LayerList.begin(); iter != iterEnd;)
	{
		if (!(*iter)->GetEnable())
		{
			++iter;
			continue;
		}
		(*iter)->Input(fDeltaTime);

		if (!(*iter)->GetLife())
		{
			SAFE_DELETE((*iter));
			iter = m_LayerList.erase(iter);
			iterEnd = m_LayerList.end();
		}
		else
			++iter;
	}
}

void CScene::Update(float fDeltaTime)
{
	list <CLayer*>::iterator iter;
	list <CLayer*>::iterator iterEnd = m_LayerList.end();

	for (iter = m_LayerList.begin(); iter != iterEnd;)
	{
		if (!(*iter)->GetEnable())
		{
			++iter;
			continue;
		}
		(*iter)->Update(fDeltaTime);

		if (!(*iter)->GetLife())
		{
			SAFE_DELETE((*iter));
			iter = m_LayerList.erase(iter);
			iterEnd = m_LayerList.end();
		}
		else
			++iter;
	}
}

void CScene::LateUpdate(float fDeltaTime)
{
	list <CLayer*>::iterator iter;
	list <CLayer*>::iterator iterEnd = m_LayerList.end();

	for (iter = m_LayerList.begin(); iter != iterEnd;)
	{
		if (!(*iter)->GetEnable())
		{
			++iter;
			continue;
		}
		(*iter)->LateUpdate(fDeltaTime);

		if (!(*iter)->GetLife())
		{
			SAFE_DELETE((*iter));
			iter = m_LayerList.erase(iter);
			iterEnd = m_LayerList.end();
		}
		else
			++iter;
	}
}

void CScene::Collision(float fDeltaTime)
{
	list <CLayer*>::iterator iter;
	list <CLayer*>::iterator iterEnd = m_LayerList.end();

	for (iter = m_LayerList.begin(); iter != iterEnd;)
	{
		if (!(*iter)->GetEnable())
		{
			++iter;
			continue;
		}
		(*iter)->Collision(fDeltaTime);

		if (!(*iter)->GetLife())
		{
			SAFE_DELETE((*iter));
			iter = m_LayerList.erase(iter);
			iterEnd = m_LayerList.end();
		}
		else
			++iter;
	}
}

void CScene::Render(HDC hDC, float fDeltaTime)
{
	list <CLayer*>::iterator iter;
	list <CLayer*>::iterator iterEnd = m_LayerList.end();

	for (iter = m_LayerList.begin(); iter != iterEnd;)
	{
		if (!(*iter)->GetEnable())
		{
			++iter;
			continue;
		}
		(*iter)->Render(hDC, fDeltaTime);

		if (!(*iter)->GetLife())
		{
			SAFE_DELETE((*iter));
			iter = m_LayerList.erase(iter);
			iterEnd = m_LayerList.end();
		}
		else
			++iter;
	}
}

bool CScene::LayerSort(CLayer* pL1, CLayer* pL2)
{
	return pL1->GetOrder() < pL2->GetOrder();
}


