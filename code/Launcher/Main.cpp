////////////////////////////////////////////////////////////////////////////
//
//  Copyright (C) Justin 2010-.
// -------------------------------------------------------------------------
//  File name: Main.cpp
//  Created:   06-08-2010 by Dongjoon Kim
//
//////////////////////////////////////////////////////////////////////////// 

#include <Windows.h>
#include <Common/IGame.h>
#include <string>

#ifdef _DEBUG
#define GAMEDLL "maind.dll"
#else
#define 
#define GAMEDLL "main.dll"
#endif

typedef Common::IGame *(*CreateFunction)();

//-----------------------------------------------------------------------------
int APIENTRY WinMain
(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
		
		//-----------------------------------------------------------------------------
		//!
		HANDLE hGame = ::LoadLibrary(GAMEDLL);
		if(!hGame)
		{
				MessageBox(0,"Fail to load game dll!", "Error", MB_OK | MB_DEFAULT_DESKTOP_ONLY);
				return 0;
		}

		//-----------------------------------------------------------------------------
		//!
		CreateFunction CreateGame = (CreateFunction)::GetProcAddress((HMODULE)(hGame), "CreateGame");

		if(!CreateGame)
		{
				MessageBox(0,"Fail to get create function!", "Error", MB_OK | MB_DEFAULT_DESKTOP_ONLY);
				::FreeLibrary((HMODULE)hGame);
				return 0;
		}

		//-----------------------------------------------------------------------------
		//!
		Common::IGame* pGame = CreateGame();

		if(!pGame)
		{
				MessageBox(0,"Fail to Create game!", "Error", MB_OK | MB_DEFAULT_DESKTOP_ONLY);
				::FreeLibrary((HMODULE)hGame);
				return 0;
		}

		::FreeLibrary((HMODULE)hGame);

		return 1;
}