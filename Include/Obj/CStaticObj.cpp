#include "CStaticObj.h"

CStaticObj::CStaticObj()
{
}

CStaticObj::CStaticObj(const CStaticObj& obj):
    CObj(obj)
{
}

CStaticObj::~CStaticObj()
{
}

void CStaticObj::Input(float fDeltaTime)
{
}

void CStaticObj::Update(float fDeltaTime)
{
}

void CStaticObj::LateUpdate(float fDeltaTime)
{
}

void CStaticObj::Collision(float fDeltaTime)
{
}

void CStaticObj::Render(HDC hDC, float fDeltaTime)
{
}
