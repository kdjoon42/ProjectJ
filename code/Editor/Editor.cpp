

#include <IEditor.h>

#include <Windows.h>
#include <string>

#include <Main/IGame.h>

#include <Main/GameStateTest.h>


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

		protected:

				Main::IGame* m_pGame;
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

		}

		//-----------------------------------------------------------------------------
		void Editor::Initialize(Main::IGame* pGame)
		{
				m_pGame = pGame;

				Core::IGameStateManager* pStateMan = m_pGame->GetGameStateManager();
				Main::GameStateTest::Create(pStateMan, "StateTest");

				pStateMan->Change(pStateMan->FindByName("StateTest"));
		}

		//-----------------------------------------------------------------------------
		void Editor::Shutdown()
		{
				m_pGame->Shutdown();
				m_pGame = 0;
				m_pInstance.reset();
		}

		//-----------------------------------------------------------------------------
		void Editor::Update()
		{
				if(m_pGame)
						m_pGame->Update();
		}

}//Ed


