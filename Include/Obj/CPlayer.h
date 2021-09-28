#pragma once
#include "CMoveObj.h"
class CPlayer :
    public CMoveObj
{
private:
	friend class CObj;
private:
    CPlayer();
	CPlayer(const CPlayer& guest);
    ~CPlayer();

private:
	float m_fMaxFallingSpeed;
	float m_fFallingSpeed;
	MOVE_DIRECTION	m_eDir;
	float m_fFallingTime;

public:
	virtual bool Init();
	virtual void Input(float fDeltaTime);
	virtual void Update(float fDeltaTime);
	virtual void LateUpdate(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Render(HDC hDC, float fDeltaTime);
	virtual	CPlayer* Clone();
};

