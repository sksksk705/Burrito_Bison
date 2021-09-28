#pragma once
#include "CScene.h"
#include "../Game.h"

class CIngameScene :
    public CScene
{
private:
    friend class CSceneManager;

private:
    CIngameScene();
    ~CIngameScene();

private:
    class CPlayer* m_pPlayer;

private:
    float m_fJellySponRate;
    float m_fJellySponEllipse;
    float m_fPlayerSpeed;

public:
    virtual bool Init();
    virtual void Update(float fDeltaTime);
};

