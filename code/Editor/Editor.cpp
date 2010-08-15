

#include <IEditor.h>

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

namespace Ed{
	
	class Editor : public IEditor
	{
	public:
		Editor();

		virtual ~Editor();

		bool Init(HWND hWnd);

	protected:
		HANDLE m_hGameDll;
		Common::IGame* m_pGame;

	};


	IEditor* IEditor::Create()
	{
		return new Editor();
	}

	Editor::Editor()
		:m_hGameDll(0),m_pGame(0)
	{
	}

	Editor::~Editor()
	{
		if(m_pGame)
		{
			m_pGame->Release();
			m_pGame = 0;
		}

		::FreeLibrary((HMODULE)m_hGameDll);
	}

	bool Editor::Init(HWND hWnd)
	{
		m_hGameDll = ::LoadLibrary(GAMEDLL);
		if(!m_hGameDll)
		{
				MessageBox(0,"Fail to load game dll!", "Error", MB_OK | MB_DEFAULT_DESKTOP_ONLY);
				return false;
		}

		//-----------------------------------------------------------------------------
		//!
		CreateFunction CreateGame = (CreateFunction)::GetProcAddress((HMODULE)(m_hGameDll), "CreateGame");

		if(!CreateGame)
		{
				MessageBox(0,"Fail to get create function!", "Error", MB_OK | MB_DEFAULT_DESKTOP_ONLY);
				::FreeLibrary((HMODULE)m_hGameDll);
				return false;
		}

		//-----------------------------------------------------------------------------
		//!
		m_pGame = CreateGame();

		if(!m_pGame)
		{
				MessageBox(0,"Fail to Create game!", "Error", MB_OK | MB_DEFAULT_DESKTOP_ONLY);
				::FreeLibrary((HMODULE)m_hGameDll);
				return false;
		}

		m_pGame->Init(hWnd);

		return true;
	}

}//Ed


