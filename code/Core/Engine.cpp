////////////////////////////////////////////////////////////////////////////
//
//  Copyright (C) Justin 2010-.
// -------------------------------------------------------------------------
//  File name: Engine.cpp
//  Created:   17-08-2010 by Dongjoon Kim
//
//////////////////////////////////////////////////////////////////////////// 

#include <Core/IEngine.h>
#include <Core/IResourceManager.h>

#include <OgreRoot.h>
#include <OgreD3D9RenderSystem.h>
#include <OgreWindowEventUtilities.h>
#include <OgreRenderWindow.h>

#include <boost/scoped_ptr.hpp>


namespace Core{

		//-----------------------------------------------------------------------------
		//!
		class Engine: public IEngine
		{
		public:
				//-----------------------------------------------------------------------------
				//!
				Engine(const Com::GameConfig& gc);

				//-----------------------------------------------------------------------------
				//!
				virtual ~Engine();

				//-----------------------------------------------------------------------------
				//!
				bool Update();
				
		protected:

				boost::scoped_ptr<IResourceManager> m_pResourceManager;

				Ogre::Root* m_pRoot;
				Ogre::RenderWindow*	m_pRenderWnd;
				Ogre::D3D9RenderSystem* m_pRenderSystem;
				Ogre::Viewport* m_pViewport;


		};

		//////////////////////////////////////////////////////////////////////////
		//

		//-----------------------------------------------------------------------------
		IEngine* IEngine::Create(const Com::GameConfig& gc)
		{
				return new Engine(gc);
		}

		//-----------------------------------------------------------------------------
		Engine::Engine(const Com::GameConfig& gc)
		{
				m_pRoot = new Ogre::Root();

				HINSTANCE hInst = GetModuleHandle( NULL );
				m_pRenderSystem = new Ogre::D3D9RenderSystem( hInst );
				m_pRoot->setRenderSystem(m_pRenderSystem);

				m_pRenderSystem->setConfigOption("Full Screen","No");
				m_pRenderSystem->setConfigOption("Allow NVPerfHUD","Yes");

				if(gc.hWnd)
				{
						m_pRoot->initialise(false);

						Ogre::NameValuePairList miscParams;
						miscParams["externalWindowHandle"] = Ogre::StringConverter::toString(reinterpret_cast<size_t>(gc.hWnd));
						m_pRenderWnd = m_pRoot->createRenderWindow("Editor", 1,1,false,&miscParams);
				}
				else
				{
						m_pRenderWnd = m_pRoot->initialise(true, "GameJ");
				}

				m_pViewport = m_pRenderWnd->addViewport(0);


				//////////////////////////////////////////////////////////////////////////
				m_pResourceManager.reset( IResourceManager::Create());

		}

		//-----------------------------------------------------------------------------
		Engine::~Engine()
		{
				m_pRoot->shutdown();
				delete m_pRenderSystem;
				delete m_pRoot;

		}

		//-----------------------------------------------------------------------------
		bool Engine::Update()
		{
				bool bContinue = !(m_pRenderWnd->isClosed());

				Ogre::WindowEventUtilities::messagePump();
		
				if(m_pRenderWnd->isActive())
				{
						float timeDelta = 0.033f;
						if(!m_pRoot->renderOneFrame(timeDelta))
								bContinue = false;
				}
				else
				{
						Sleep(1000);
				}

				return bContinue;
		}
		


}//Main