////////////////////////////////////////////////////////////////////////////
//
//  Copyright (C) Justin 2010-.
// -------------------------------------------------------------------------
//  File name: GameConfig.h
//  Created:   19-08-2010 by Dongjoon Kim
//
//////////////////////////////////////////////////////////////////////////// 

#pragma once

#include <Windows.h>

namespace Com
{
		//-----------------------------------------------------------------------------
		//!
		struct GameConfig
		{
				GameConfig():hWnd(0){}

				HWND hWnd;
		};

}// Com