#include "CMoveObj.h"

CMoveObj::CMoveObj() :
	m_fAngle(0.f),
	m_fSpeed(0.f),
	m_eDir(MD_NONE)
{
}

CMoveObj::CMoveObj(const CMoveObj& obj) :
	CObj(obj)
{
	m_fAngle = obj.m_fAngle;
	m_fSpeed = obj.m_fSpeed;
	m_eDir = obj.m_eDir;
}

CMoveObj::~CMoveObj()
{
}

void CMoveObj::Move(float x, float y)
{
	m_tPos.x += x * m_eDir;
	m_tPos.y += y * m_eDir;
}

void CMoveObj::Move(float x, float y, float fDeltaTime)
{
	m_tPos.x += x * fDeltaTime * m_eDir;
	m_tPos.y += y * fDeltaTime * m_eDir;
}

void CMoveObj::Move(const POSITION& tMove)
{
	m_tPos += tMove * m_eDir;
}

void CMoveObj::Move(const POSITION& tMove, float fDeltaTime)
{
	m_tPos += tMove * fDeltaTime * m_eDir;
}

void CMoveObj::MoveX(float x)
{
	m_tPos.x += x * m_eDir;
}

void CMoveObj::MoveX(float x, float fDeltaTime)
{
	m_tPos.x += x * fDeltaTime * m_eDir;
}

void CMoveObj::MoveY(float y)
{
	m_tPos.y += y * m_eDir;
}

void CMoveObj::MoveY(float y, float fDeltaTime)
{
	m_tPos.y += y * fDeltaTime * m_eDir;
}

void CMoveObj::MoveAngle(float fSpeed)
{
	m_tPos.x += cosf(m_fAngle) * fSpeed;
	m_tPos.y += sinf(m_fAngle) * fSpeed;
}

void CMoveObj::MoveAngle(float fSpeed, float fDeltaTime)
{
	m_tPos.x += cosf(m_fAngle) * fSpeed * fDeltaTime;
	m_tPos.y += sinf(m_fAngle) * fSpeed * fDeltaTime;
}


void CMoveObj::Input(float fDeltaTime)
{
	CObj::Input(fDeltaTime);
}

void CMoveObj::Update(float fDeltaTime)
{
	CObj::Update(fDeltaTime);
}

void CMoveObj::LateUpdate(float fDeltaTime)
{
}

void CMoveObj::Collision(float fDeltaTime)
{
	CObj::Collision( fDeltaTime);
}

void CMoveObj::Render(HDC hDC, float fDeltaTime)
{
	CObj::Render(hDC, fDeltaTime);
}
