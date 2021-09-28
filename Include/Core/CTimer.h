#pragma once
#include "../Game.h"
class CTimer
{
private:
	HWND			m_hWnd;
	LARGE_INTEGER	m_tSecond;
	LARGE_INTEGER	m_tTime;
	float			m_fDeltaTime;
	float			m_fTimeScale;
	float			m_fFPS;
	float			m_fFPSTime;
	int				m_iFrameMax;
	int				m_iFrame;

	
public:

	float GetDeltaTime()const
	{
		return m_fDeltaTime * m_fTimeScale;
	}
	float GetFps()const
	{
		return m_fFPS;
	}
	float GetTimeScale() const
	{
		return m_fTimeScale;
	}

	void SetTimeSacle(float fTimeScale)
	{
		m_fTimeScale = fTimeScale;
	}
public:
	bool Init(HWND hWnd);
	void Update();


	DECLARE_SINGLE(CTimer)
};

