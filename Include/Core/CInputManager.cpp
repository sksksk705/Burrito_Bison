#include "CInputManager.h"

DEFINITION_SINGLE(CInputManager)
CInputManager::CInputManager():
    m_pCreateKey(NULL)
{
}

CInputManager::~CInputManager()
{
    Safe_Delete_Map(m_mapKey);
}

bool CInputManager::Init(HWND hWnd)
{
    m_hWnd = hWnd;

    AddKey("LButton", VK_LBUTTON);

    return true;
}

void CInputManager::Update(float fDeltaTime)
{
    unordered_map<string, PKEYINFO>::iterator   iter;
    unordered_map<string, PKEYINFO>::iterator   iterEnd = m_mapKey.end();
    for (iter = m_mapKey.begin(); iter != iterEnd; ++iter)
    {
        int iPushCount = 0;
        for (size_t i = 0; i < iter->second->vecKey.size(); ++i)
        {
            if (GetAsyncKeyState(iter->second->vecKey[i]) & 0x8000)
                ++iPushCount;
        }

        if (iPushCount == iter->second->vecKey.size())
        {
            if (!iter->second->bDown && !iter->second->bPress)
            {
                iter->second->bDown = true;
                iter->second->bPress = true;
            }

            else if (iter->second->bDown && !iter->second->bPress)
            {
                iter->second->bDown = false;
            }
        }
        else
        {
            if (iter->second->bDown || iter->second->bPress)
            {
                iter->second->bUp = true;
                iter->second->bDown = false;
                iter->second->bPress = false;
            }
            else if (iter->second->bUp)
                iter->second->bUp = false;
        }
    }
}

bool CInputManager::KeyDown(const string& strKey) const
{
    PKEYINFO    pInfo = FindKey(strKey);
    
    if (!pInfo)
        return false;

    return pInfo->bDown;
}

bool CInputManager::KeyPress(const string& strKey) const
{
    PKEYINFO    pInfo = FindKey(strKey);

    if (!pInfo)
        return false;

    return pInfo->bPress;
}

bool CInputManager::KeyUp(const string& strKey) const
{
    PKEYINFO    pInfo = FindKey(strKey);

    if (!pInfo)
        return pInfo->bUp;

    return pInfo->bDown;
}

PKEYINFO CInputManager::FindKey(const string& strKey) const
{
    unordered_map<string, PKEYINFO>::const_iterator   iter = m_mapKey.find(strKey);

    if (iter == m_mapKey.end())
        return NULL;

    return iter->second;
}
