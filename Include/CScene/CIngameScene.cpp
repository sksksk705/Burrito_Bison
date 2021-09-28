#include "CIngameScene.h"
#include "../Core.h"
#include "../Obj/CPlayer.h"
#include "../Obj/CJelly.h"
#include "../Obj/CStage.h"
#include "CLayer.h"
#include "../Core/CCamera.h"

CIngameScene::CIngameScene():
	m_fJellySponEllipse(0.f),
	m_fJellySponRate(0.f),
	m_pPlayer(NULL)
{
}

CIngameScene::~CIngameScene()
{
	SAFE_RELEASE(m_pPlayer);
}

bool CIngameScene::Init()
{
	m_fJellySponRate = 0.5f;

	if (!CScene::Init())
		return false;

	CLayer* pLayer = FindLayer("Default");

	CPlayer* pPlayer = CObj::CreateObj<CPlayer>("Player", pLayer);

	m_pPlayer = pPlayer;

	GET_SINGLE(CCamera)->SetTarget(pPlayer);

	SAFE_RELEASE(pPlayer);

	CJelly* pJelly = CScene::CreatePrototype<CJelly>("NormalJelly");

	pJelly->Init();

	SAFE_RELEASE(pJelly);

	CLayer* pStageLayer = FindLayer("Stage");

	CStage* pStage = CObj::CreateObj<CStage>("Stage", pStageLayer);

	SAFE_RELEASE(pStage);

	return true;
}

void CIngameScene::Update(float fDeltaTime)
{
	CScene::Update(fDeltaTime);

	m_fJellySponEllipse += fDeltaTime;
	if (m_fJellySponEllipse >= m_fJellySponRate)
	{
		m_fJellySponEllipse -= m_fJellySponRate;

		CLayer* pLayer = FindLayer("Default");

		CObj* pJelly = CObj::CreateCloneObj("NormalJelly", "NormalJelly", pLayer);

		pJelly->SetPos(GET_SINGLE(CCamera)->GetPos().x + GET_RESOLUTION.iW, GET_WORLDRESOLUTION.iH - 269);


		SAFE_RELEASE(pJelly);
	}
}
