#include "EdFrame.h"
#include <Common/IGame.h>

#include <IEditor.h>
#include <EdViewPanel.h>
#include <EdRenderView.h>

//-----------------------------------------------------------------------------
EdFrame::EdFrame( wxWindow* parent )
:Frame( parent ),m_pEditor(0)
{
		m_pRenderView = new EdRenderView(m_panelMain,wxID_ANY);
		wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);
		vbox->Add(m_pRenderView, 1, wxEXPAND | wxALL, 0);
		m_panelMain->SetSizer(vbox);

}

//-----------------------------------------------------------------------------
void EdFrame::Init()
{
		Main::GameConfig gc;
		gc.hWnd = (HWND)(m_pRenderView->GetHandle());

		m_pEditor = &Ed::IEditor::Instance();

		Main::IGame* pGame = Ed::IEditor::Instance().GetGame();

		if(pGame->Initialize(gc))
				Ed::IEditor::Instance().Initialize(pGame);
}

//-----------------------------------------------------------------------------
void EdFrame::OnClose( wxCloseEvent& event )
{
		Ed::IEditor::Instance().Shutdown();
		m_pEditor = 0;

		event.Skip();
}

//-----------------------------------------------------------------------------
void EdFrame::OnIdle( wxIdleEvent& event )
{
		if(m_pEditor)
				m_pEditor->Update();
		//else
		//		Ed::IEditor::Instance().Shutdown();

		event.Skip();		
}