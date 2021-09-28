#include "Core.h"
#include "CScene/CSceneManager.h"
#include "Core/CTimer.h"
#include "Core/CPathManager.h"
#include "Resource/CResourceManager.h"
#include "Resource/CTexture.h"
#include "Core/CCamera.h"
#include "Core/CInputManager.h"

DEFINITION_SINGLE(CCore)
bool CCore::m_bLoop = true;

CCore::CCore()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(244);
}

CCore::~CCore()
{
	DESTROY_SINGLE(CSceneManager);
	DESTROY_SINGLE(CCamera);
	DESTROY_SINGLE(CTimer);
	DESTROY_SINGLE(CPathManager);
	DESTROY_SINGLE(CResourceManager);
	DESTROY_SINGLE(CInputManager);

	ReleaseDC(m_hWnd, m_hDC);
}

bool CCore::Init(HINSTANCE hInst)
{
    m_hInst = hInst;

	MyRegisterClass();

	m_tRS.iW = 1280;
	m_tRS.iH = 720;

	if (!Create())
		return false;

	m_hDC = GetDC(m_hWnd);


	if (!GET_SINGLE(CTimer)->Init(m_hWnd))
		return false;

	if (!GET_SINGLE(CPathManager)->Init())
		return false;

	if (!GET_SINGLE(CInputManager)->Init(m_hWnd))
		return false;
	
	if (!GET_SINGLE(CResourceManager)->Init(m_hInst, m_hDC))
		return false;

	if(!GET_SINGLE(CCamera)->Init(POSITION(0.f, 0.f),m_tRS,RESOLUTION(3840, 1443)))
		return false;

	if (!GET_SINGLE(CSceneManager)->Init())
		return false;

    return true;
}

BOOL CCore::Create()
{

	m_hWnd = CreateWindowW(L"때부자", L"때부자", WS_OVERLAPPEDWINDOW,
		100, 0, CW_USEDEFAULT, 0, nullptr, nullptr, m_hInst, nullptr);

	if (!m_hWnd)
	{
		return FALSE;
	}

	RECT rc = { 0 , 0 , m_tRS.iW, m_tRS.iH};

	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
	SetWindowPos(m_hWnd, HWND_TOPMOST, 100, 100, rc.right - rc.left, rc.bottom - rc.top, SWP_NOMOVE | SWP_NOZORDER);


	ShowWindow(m_hWnd, SW_SHOW);
	UpdateWindow(m_hWnd);

	return TRUE;

}

int CCore::Run()
{
	MSG msg;

	// 기본 메시지 루프입니다:
	while (m_bLoop)
	{
		if (PeekMessage(&msg,nullptr,0,0,PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			Logic();
		}
	}

	return (int)msg.wParam;
}

void CCore::Logic()
{
	GET_SINGLE(CTimer)->Update();

	float fDeltaTime = GET_SINGLE(CTimer)->GetDeltaTime();

	Input(fDeltaTime);
	Update(fDeltaTime);
	LateUpdate(fDeltaTime);
	Collision(fDeltaTime);
	Render(fDeltaTime);

}

void CCore::Input(float fDeltaTime)
{
	GET_SINGLE(CSceneManager)->Input(fDeltaTime);
	GET_SINGLE(CCamera)->Input(fDeltaTime);
}

void CCore::Update(float fDeltaTime)
{
	GET_SINGLE(CSceneManager)->Update(fDeltaTime);
	GET_SINGLE(CCamera)->Update(fDeltaTime);
	GET_SINGLE(CInputManager)->Update(fDeltaTime);
}

void CCore::LateUpdate(float fDeltaTime)
{
	GET_SINGLE(CSceneManager)->LateUpdate(fDeltaTime);
}

void CCore::Collision(float fDeltaTime)
{
	GET_SINGLE(CSceneManager)->Collision(fDeltaTime);
}

void CCore::Render(float fDeltaTime)
{
	CTexture* pBackBuffer = GET_SINGLE(CResourceManager)->GetBackBuffer();

	Rectangle(pBackBuffer->GetDC(), 0, 0, m_tRS.iW, m_tRS.iH);

	GET_SINGLE(CSceneManager)->Render(pBackBuffer->GetDC(), fDeltaTime);

	BitBlt(m_hDC, 0, 0, m_tRS.iW, m_tRS.iH, pBackBuffer->GetDC(), 0, 0, SRCCOPY);

	SAFE_RELEASE(pBackBuffer);
}

ATOM CCore::MyRegisterClass()
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = m_hInst;
    wcex.hIcon = LoadIcon(m_hInst, MAKEINTRESOURCE(IDI_ICON1));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = NULL;//MAKEINTRESOURCEW(IDC_MY20210819);
    wcex.lpszClassName = L"때부자";
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON1));

    return RegisterClassExW(&wcex);

}

LRESULT CCore::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		m_bLoop = false;
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
