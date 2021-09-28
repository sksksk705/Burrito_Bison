#pragma once
#include "CMoveObj.h"
class CJelly :
    public CMoveObj
{
private:
    friend class CObj;
	friend class CScene;

private:
    CJelly();
    CJelly(const CJelly& jelly);
    ~CJelly();

public:
	virtual bool Init();
	virtual void Input(float fDeltaTime);
	virtual void Update(float fDeltaTime);
	virtual void LateUpdate(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Render(HDC hDC, float fDeltaTime);
	virtual	CJelly* Clone();
};

