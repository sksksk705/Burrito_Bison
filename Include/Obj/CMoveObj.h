#pragma once
#include "CObj.h"
class CMoveObj :
    public CObj
{
protected:
    CMoveObj();
	CMoveObj(const CMoveObj& obj);
    virtual ~CMoveObj();

protected:
	MOVE_DIRECTION	m_eDir;
	float m_fAngle;
	float m_fSpeed;

public:
	void SetAngle(float fAngle)
	{
		m_fAngle = fAngle;
	}
	void SetSpeed(float fSpeed)
	{
		m_fSpeed = fSpeed;
	}

	float GetAngle() const
	{
		return m_fAngle;
	}
	
	float GetSpeed() const 
	{
		return m_fSpeed;
	}

	void SetDirection(MOVE_DIRECTION eDir)
	{
		m_eDir = eDir;
	}

	MOVE_DIRECTION GetDirection() const
	{
		return m_eDir;
	}
	
	

public:
	void Move(float x, float y);
	void Move(float x, float y, float fDeltaTime);
	void Move(const POSITION& tMove);
	void Move(const POSITION& tMove, float fDeltaTime);
	void MoveX(float x);
	void MoveX(float x, float fDeltaTime);
	void MoveY(float y);
	void MoveY(float y, float fDeltaTime);
	void MoveAngle(float fSpeed);
	void MoveAngle(float fSpeed, float fDeltaTime);


public:
	virtual bool Init() = 0;
	virtual void Input(float fDeltaTime);
	virtual void Update(float fDeltaTime);
	virtual void LateUpdate(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Render(HDC hDC, float fDeltaTime);
	virtual	CMoveObj* Clone() = 0;
};

