#include "CSceneManager.h"
#include "CIngameScene.h"

DEFINITION_SINGLE(CSceneManager)

CSceneManager::CSceneManager():
	m_pScene(NULL),
	m_pNextScene(NULL)
{
}

CSceneManager::~CSceneManager()
{
	SAFE_DELETE(m_pScene);
}

bool CSceneManager::Init()
{
	CreateScene<CIngameScene>();
	return true;
}

void CSceneManager::Input(float fDeltaTime)
{
	m_pScene->Input(fDeltaTime);
}

void CSceneManager::Update(float fDeltaTime)
{
	m_pScene->Update(fDeltaTime);
}

void CSceneManager::LateUpdate(float fDeltaTime)
{
	m_pScene->LateUpdate(fDeltaTime);
}

void CSceneManager::Collision(float fDeltaTime)
{
	m_pScene->Collision(fDeltaTime);
}

void CSceneManager::Render(HDC hDC, float fDeltaTime)
{
	m_pScene->Render(hDC, fDeltaTime);
}
