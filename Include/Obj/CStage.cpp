#include "CStage.h"
#include "../Resource/CTexture.h"
#include "../Core.h"
#include "../Core/CCamera.h"

CStage::CStage()
{
}

CStage::CStage(const CStage& stage):
    CStaticObj(stage)
{
}

CStage::~CStage()
{
}

bool CStage::Init()
{
    SetPos(0, 0);
    SetSize(3840.f, 1443.f);
    SetPivot(0.f, 0.f);

    SetTexture("Stage", L"Stage.bmp");
    return true;
}

void CStage::Input(float fDeltaTime)
{
    CStaticObj::Input(fDeltaTime);
}

void CStage::Update(float fDeltaTime)
{
    CStaticObj::Update(fDeltaTime);
}

void CStage::LateUpdate(float fDeltaTime)
{
    CStaticObj::LateUpdate(fDeltaTime);
}

void CStage::Collision(float fDeltaTime)
{
    CStaticObj::Collision(fDeltaTime);
}

void CStage::Render(HDC hDC, float fDeltaTime)
{
    //CStaticObj::Render(hDC, fDeltaTime);
    if (m_pTexture)
    {
        POSITION    tPos = m_tPos - m_tSize * m_tPivot;
        POSITION    tCamPos = GET_SINGLE(CCamera)->GetPos();

        BitBlt(hDC, tPos.x, tPos.y, m_tSize.x, m_tSize.y, m_pTexture->GetDC(), tCamPos.x, tCamPos.y, SRCCOPY);
    }
}

CStage* CStage::Clone()
{
    return new CStage(*this);
}
