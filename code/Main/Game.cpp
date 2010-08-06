////////////////////////////////////////////////////////////////////////////
//
//  Copyright (C) Justin 2010-.
// -------------------------------------------------------------------------
//  File name: Game.cpp
//  Created:   06-08-2010 by Dongjoon Kim
//
//////////////////////////////////////////////////////////////////////////// 

#include <Windows.h>
#include <new>

#include <Main/Game.h>

namespace Main{

		//-----------------------------------------------------------------------------
		Common::IGame* Game::Create()
		{
				static char buff[sizeof(Game)];
				return new (buff) Game;
		}

}//Main