#include "CPlayer.h"
#include "../Core.h"
#include "../Core/CCamera.h"
#include "../Resource/CTexture.h"
#include "../Core/CInputManager.h"

CPlayer::CPlayer() :
	m_fFallingSpeed(0.f),
	m_fMaxFallingSpeed(0.f),
	m_eDir(MD_NONE)
{
}

CPlayer::CPlayer(const CPlayer& guest):
	CMoveObj(guest)
{
}

CPlayer::~CPlayer()
{
}

bool CPlayer::Init()
{
	SetPos(100.f, GET_WORLDRESOLUTION.iH - 500);
	SetSize(100.f, 100.f);
	SetDirection(MD_FRONT);
	SetSpeed(300.f);
	SetPivot(0.5f, 1.f);
	m_eDir = MD_FRONT;
	m_fMaxFallingSpeed = 1200.f;

	SetTexture("Player", L"Player.bmp");
	m_pTexture->SetColorKey(24, 71, 60);

	return true;
}

void CPlayer::Input(float fDeltaTime)
{
	CMoveObj::Input(fDeltaTime);

	if (KEYDOWN("LButton"))
	{
		m_fFallingSpeed = m_fMaxFallingSpeed;
	}
}

void CPlayer::Update(float fDeltaTime)
{
	CMoveObj::Update(fDeltaTime);
	

	if (m_tPos.y + m_tSize.y * m_tPivot.y <= 0)
		m_fFallingSpeed = m_fMaxFallingSpeed;

	if (m_fFallingSpeed < 0)
		m_fFallingSpeed += (GET_WORLDRESOLUTION.iH - m_tPos.y) / 1000 * GRAVITY * fDeltaTime;

	m_fFallingSpeed += GRAVITY * fDeltaTime;



	if (m_fFallingSpeed >= m_fMaxFallingSpeed)
		m_fFallingSpeed = m_fMaxFallingSpeed;

	if (m_tPos.x + m_tSize.x * m_tPivot.x >= GET_WORLDRESOLUTION.iW)
	{
		m_fSpeed -= 100.f;
	}

	if (m_tPos.y >= GET_WORLDRESOLUTION.iH - 270)
	{
		if (m_fFallingSpeed != m_fMaxFallingSpeed)
		{
			m_fSpeed -= 2.f;
		}
		m_fFallingSpeed *= -1.f;
		m_fFallingTime = 0.f;

		if (m_fSpeed <= 0.f)
		{
			m_fFallingSpeed = 0.f;
		}
	}

	if (m_fSpeed <= 0.f)
	{
		m_fSpeed = 0.f;
	}

	m_tPos.y -= -(m_fFallingSpeed * fDeltaTime);
	m_tPos.x += m_fSpeed * fDeltaTime;

}

void CPlayer::LateUpdate(float fDeltaTime)
{
	CMoveObj::LateUpdate(fDeltaTime);
}

void CPlayer::Collision(float fDeltaTime)
{
	CMoveObj::Collision(fDeltaTime);
}

void CPlayer::Render(HDC hDC, float fDeltaTime)
{
	CMoveObj::Render(hDC, fDeltaTime);
	//Rectangle(hDC, m_tPos.x, m_tPos.y, m_tPos.x + m_tSize.x, m_tPos.y + m_tSize.y);
}

CPlayer* CPlayer::Clone()
{
	return new CPlayer(*this);
}
