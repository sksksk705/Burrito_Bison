#pragma once
#include "Game.h"

class CCore
{
private:
	static bool	m_bLoop;

private:
	HINSTANCE	m_hInst;
	HWND		m_hWnd;
	RESOLUTION	m_tRS;
	HDC			m_hDC;

public:
	bool Init(HINSTANCE	hInst);
	BOOL Create();
	int Run();
private:
	void Logic();
	void Input(float fDeltaTime);
	void Update(float fDeltaTime);
	void LateUpdate(float fDeltaTime);
	void Collision(float fDeltaTime);
	void Render( float fDeltaTime);

public:
	RESOLUTION	GetResolution() const
	{
		return m_tRS;
	}
	void Gameover()
	{
		m_bLoop = false;
	}


private:
	ATOM MyRegisterClass();
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	DECLARE_SINGLE(CCore)

};

