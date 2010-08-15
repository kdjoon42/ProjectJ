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

#include <OgreRoot.h>

namespace Main{

		//-----------------------------------------------------------------------------
		Common::IGame* Game::Create()
		{
				static char buff[sizeof(Game)];
				return new (buff) Game;
		}

		Game::Game()
			:m_pRoot(0){}

		void Game::Init(HWND hWnd)
		{
			m_pRoot = new Ogre::Root;
		}

		void Game::Release()
		{
			if(m_pRoot)
			{
				delete m_pRoot;
				m_pRoot = 0;
			}
		}

}//Main