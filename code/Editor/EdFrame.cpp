#include "EdFrame.h"
#include <Common/IGame.h>

#include <IEditor.h>
#include <EdViewPanel.h>

//-----------------------------------------------------------------------------
EdFrame::EdFrame( wxWindow* parent )
:Frame( parent )
{	
}

//-----------------------------------------------------------------------------
void EdFrame::Init()
{
		Main::GameConfig gc;
		gc.hWnd = (HWND)(m_panelMain->GetHandle());

		Main::IGame* pGame = Ed::IEditor::Instance().GetGame();

		if(pGame->Initialize(gc))
				Ed::IEditor::Instance().Initialize(pGame);
}

//-----------------------------------------------------------------------------
void EdFrame::OnClose( wxCloseEvent& event )
{
		Ed::IEditor::Instance().Shutdown();

		event.Skip();
}

//-----------------------------------------------------------------------------
void EdFrame::OnIdle( wxIdleEvent& event )
{
		Ed::IEditor::Instance().Update();

		event.Skip();		
}