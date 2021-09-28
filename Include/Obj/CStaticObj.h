#pragma once
#include "CObj.h"
class CStaticObj :
	public CObj
{
protected:
	CStaticObj();
	CStaticObj(const CStaticObj& obj);
	virtual ~CStaticObj();

public:
	virtual bool Init() = 0;
	virtual void Input(float fDeltaTime);
	virtual void Update(float fDeltaTime);
	virtual void LateUpdate(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Render(HDC hDC, float fDeltaTime);
	virtual	CStaticObj* Clone() = 0;
};

