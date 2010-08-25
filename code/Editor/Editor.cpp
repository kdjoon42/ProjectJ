

#include <IEditor.h>

#include <Windows.h>
#include <string>

#include <Main/IGame.h>
#include <Core/IGrid.h>
#include <Core/IEngine.h>
#include <Core/ICameraManipulator.h>

#include <Main/GameStateTest.h>

#include <OgreVector3.h>

namespace Ed{

		//-----------------------------------------------------------------------------
		//!
		class Editor : public IEditor
		{
		public:
				//-----------------------------------------------------------------------------
				//!
				Editor();

				//-----------------------------------------------------------------------------
				//!
				virtual ~Editor();

				//-----------------------------------------------------------------------------
				//!
				void Initialize(Main::IGame* pGame);

				//-----------------------------------------------------------------------------
				//!
				void Shutdown();

				//-----------------------------------------------------------------------------
				//!
				Main::IGame* GetGame() { return &Main::IGame::Instance(); }

				//-----------------------------------------------------------------------------
				//!
				void Update();

				//-----------------------------------------------------------------------------
				//!
				Core::ICameraManipulator* GetCamManipulator() { return m_pCamManipulator.get(); }

		protected:

				Main::IGame* m_pGame;
				boost::scoped_ptr<Core::IGrid> m_pGrid;
				boost::scoped_ptr<Core::ICameraManipulator> m_pCamManipulator;
		};

		//-----------------------------------------------------------------------------
		//!
		boost::scoped_ptr<IEditor> IEditor::m_pInstance;

		//-----------------------------------------------------------------------------
		IEditor& IEditor::Instance()
		{
				if(!m_pInstance)
				{
						m_pInstance.reset(new Editor());
				}

				return *m_pInstance;
		}

		//-----------------------------------------------------------------------------
		Editor::Editor()
				:m_pGame(0)
		{
		}

		//-----------------------------------------------------------------------------
		Editor::~Editor()
		{
				m_pGrid.reset();

				if(m_pGame)
				{
						m_pGame->Shutdown();
						m_pGame = 0;
				}
		}

		//-----------------------------------------------------------------------------
		void Editor::Initialize(Main::IGame* pGame)
		{
				m_pGame = pGame;

				Core::IGameStateManager* pStateMan = m_pGame->GetGameStateManager();
				Main::GameStateTest::Create(pStateMan, "StateTest");

				pStateMan->Change(pStateMan->FindByName("StateTest"));

				m_pGrid.reset(m_pGame->GetEngine()->CreateGrid());
				m_pGrid->Initialze(100.f, 1.f);

				m_pCamManipulator.reset(m_pGame->GetEngine()->CreateCameraManipulator());
				m_pCamManipulator->Set(Ogre::Vector3(-50.f, 0.f, 50.f),Ogre::Vector3(0,0,0));
		}

		//-----------------------------------------------------------------------------
		void Editor::Shutdown()
		{
				m_pInstance.reset();
		}

		//-----------------------------------------------------------------------------
		void Editor::Update()
		{
				if(m_pGame)
						m_pGame->Update();
		}

}//Ed


