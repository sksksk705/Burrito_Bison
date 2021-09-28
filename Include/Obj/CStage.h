#pragma once
#include "CStaticObj.h"
class CStage :
    public CStaticObj
{
private:
	friend class CObj;

protected:
	CStage();
	CStage(const CStage& stage);
	virtual ~CStage();

public:
	virtual bool Init();
	virtual void Input(float fDeltaTime);
	virtual void Update(float fDeltaTime);
	virtual void LateUpdate(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Render(HDC hDC, float fDeltaTime);
	virtual	CStage* Clone();
};

