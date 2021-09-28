#pragma once

#define SAFE_DELETE(p)	if(p)	{delete p; p = NULL;}
#define SAFE_DELETE_ARRAY(p)	if(p)	{delete[] p; p = NULL;}
#define SAFE_RELEASE(p)		if(p)		{p->Release();p = NULL;}

#define DECLARE_SINGLE(Type)	\
		private:\
			static Type* m_pInst;\
		private:\
			Type();\
			~Type();\
		public:\
			static Type* GetInst()\
			{\
				if(!m_pInst)\
					m_pInst = new Type; \
				return m_pInst;\
			}\
			static void DestroyInst()\
			{\
				SAFE_DELETE(m_pInst);\
			}

#define DEFINITION_SINGLE(Type)	Type* Type::m_pInst = NULL;
#define GET_SINGLE(Type)		Type::GetInst()
#define DESTROY_SINGLE(Type)	Type::DestroyInst()
#define GET_RESOLUTION			CCore::GetInst()->GetResolution()
#define GET_WORLDRESOLUTION		CCamera::GetInst()->GetWorldRS()
#define GAMEOVER				CCore::GetInst()->Gameover()

#define KEYDOWN(key)			CInputManager::GetInst()->KeyDown(key)
#define KEYPRESS(key)			CInputManager::GetInst()->KeyPress(key)
#define KEYUP(key)				CInputManager::GetInst()->KeyUp(key)