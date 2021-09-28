#pragma once

#include <Windows.h>
#include <list>
#include <vector>
#include <unordered_map>
#include <crtdbg.h>
#include <typeinfo>

#pragma comment(lib, "msimg32")

using namespace std;

#include "Macro.h"
#include "type.h"
#include "resource.h"
#include "flag.h"

#define GRAVITY		9.8f
#define PI			3.141592f
#define ROOT_PATH		"RootPath"
#define TEXTURE_PATH	"TexturePath"


template<typename T>
void Safe_Delete_VecList(T& p)
{
	typename T::iterator	iter;
	typename T::iterator	iterEnd = p.end();
	for (iter = p.begin(); iter != iterEnd; ++iter)
	{
		SAFE_DELETE((*iter));

	}
	p.clear();
}

template<typename T>
void Safe_Release_VecList(T& p)
{
	typename T::iterator	iter;
	typename T::iterator	iterEnd = p.end();
	for (iter = p.begin(); iter != iterEnd; ++iter)
	{
		SAFE_RELEASE((*iter));

	}
	p.clear();
}

template<typename T>
void Safe_Release_Map(T& p)
{
	typename T::iterator	iter;
	typename T::iterator	iterEnd = p.end();
	for (iter = p.begin(); iter != iterEnd; ++iter)
	{
		SAFE_RELEASE(iter->second);

	}
	p.clear();
}


template<typename T>
void Safe_Delete_Map(T& p)
{
	typename T::iterator	iter;
	typename T::iterator	iterEnd = p.end();
	for (iter = p.begin(); iter != iterEnd; ++iter)
	{
		SAFE_DELETE(iter->second);

	}
	p.clear();
}