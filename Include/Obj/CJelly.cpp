#include "CJelly.h"
#include "../Core.h"
#include "../Obj/CPlayer.h"
#include "../Core/CCamera.h"
#include "../Resource/CTexture.h"
#include "../Core.h"
CJelly::CJelly()
{
}

CJelly::CJelly(const CJelly& jelly):
    CMoveObj(jelly)
{
}

CJelly::~CJelly()
{
}

bool CJelly::Init()
{
    SetSize(50.f, 50.f);
    SetPivot(0.5f, 1.0f);
    SetSpeed(-50.f);
    SetDirection(MD_BACK);

    SetTexture("Jelly", L"Jelly.bmp");
    m_pTexture->SetColorKey(24, 71, 60);

    return true;
}

void CJelly::Input(float fDeltaTime)
{
    CMoveObj::Input(fDeltaTime);
}

void CJelly::Update(float fDeltaTime)
{
    CMoveObj::Update(fDeltaTime);

    MoveX(GetSpeed() * fDeltaTime);
}

void CJelly::LateUpdate(float fDeltaTime)
{
    CMoveObj::LateUpdate(fDeltaTime);
}

void CJelly::Collision(float fDeltaTime)
{
    CMoveObj::Collision(fDeltaTime);
}

void CJelly::Render(HDC hDC, float fDeltaTime)
{
    CMoveObj::Render(hDC, fDeltaTime);
}

CJelly* CJelly::Clone()
{
    return new CJelly(*this);
}
