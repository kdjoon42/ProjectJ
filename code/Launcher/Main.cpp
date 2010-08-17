////////////////////////////////////////////////////////////////////////////
//
//  Copyright (C) Justin 2010-.
// -------------------------------------------------------------------------
//  File name: Main.cpp
//  Created:   06-08-2010 by Dongjoon Kim
//
//////////////////////////////////////////////////////////////////////////// 

#include <Windows.h>
#include <string>

#include <Common/IGame.h>

//-----------------------------------------------------------------------------
int APIENTRY WinMain
(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
		
		Main::GameConfig gc;
		Main::IGame& game = Main::IGame::Instance();

		if(!game.Initialize(gc))
		{
				return 0;
		}

		while(game.Update());

		game.Shutdown();

		return 1;
}