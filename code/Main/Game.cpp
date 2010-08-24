////////////////////////////////////////////////////////////////////////////
//
//  Copyright (C) Justin 2010-.
// -------------------------------------------------------------------------
//  File name: Game.cpp
//  Created:   06-08-2010 by Dongjoon Kim
//
//////////////////////////////////////////////////////////////////////////// 

#include <Main/IGame.h>
#include <Core/IEngine.h>
#include <Core/ILevelSystem.h>
#include <Core/IGameStateManager.h>

#include <Windows.h>
#include <boost/scoped_ptr.hpp>

namespace Main{

		//-----------------------------------------------------------------------------
		//!
		class Game : public IGame
		{
		public:
				//-----------------------------------------------------------------------------
				//!
				Game();

				//-----------------------------------------------------------------------------
				//!
				~Game();

				//-----------------------------------------------------------------------------
				//!
				bool Initialize(const Com::GameConfig& config);

				//-----------------------------------------------------------------------------
				//!
				void Shutdown();

				//-----------------------------------------------------------------------------
				//!
				bool Update();

				//-----------------------------------------------------------------------------
				//!
				void Quit() { m_bQuit = true; }

				//-----------------------------------------------------------------------------
				//!
				Core::IGameStateManager* GetGameStateManager() { return m_pGameStateManager.get(); }

				//-----------------------------------------------------------------------------
				//!
				Core::IEngine* GetEngine() { return m_pEngine.get(); }

		protected:
				bool m_bQuit;

				boost::scoped_ptr<Core::IEngine> m_pEngine;
				boost::scoped_ptr<Core::ILevelSystem> m_pLevelSystem;
				boost::scoped_ptr<Core::IGameStateManager> m_pGameStateManager;
		};

		//////////////////////////////////////////////////////////////////////////
		//

		//-----------------------------------------------------------------------------
		boost::scoped_ptr<IGame> IGame::m_pInstance;

		//-----------------------------------------------------------------------------
		IGame& IGame::Instance()
		{
				if(!m_pInstance)
				{
						m_pInstance.reset(new Game());
				}

				return *m_pInstance;
		}

		//-----------------------------------------------------------------------------
		Game::Game()
				:m_bQuit(true)
		{

		}

		//-----------------------------------------------------------------------------
		Game::~Game()
		{

		}


		//-----------------------------------------------------------------------------
		bool Game::Initialize(const Com::GameConfig& config)
		{
				m_pEngine.reset(Core::IEngine::Create(config));

				m_pLevelSystem.reset(Core::ILevelSystem::Create());

				m_pGameStateManager.reset(Core::IGameStateManager::Create());

				m_bQuit = false;

				return true;
		}

		//-----------------------------------------------------------------------------
		void Game::Shutdown()
		{
				m_pInstance.reset();
		}

		//-----------------------------------------------------------------------------
		bool Game::Update()
		{
				if(m_pGameStateManager)
						m_pGameStateManager->Update(0.033f);

				if(!m_pEngine->Update())
						m_bQuit = true;

				return m_bQuit ? false : true;
		}

}//Main