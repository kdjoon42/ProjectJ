#include "EdFrame.h"
#include <Common/GameConfig.h>
#include <Main/IGame.h>

#include <IEditor.h>
#include <EdViewPanel.h>
#include <EdRenderView.h>

#define ID_TIMER 1000
#define TIMER_INTERVAL 33

//-----------------------------------------------------------------------------
EdFrame::EdFrame( wxWindow* parent )
:Frame( parent ),m_pEditor(0)
{
		m_pRenderView = new EdRenderView(m_panelMain,wxID_ANY);
		wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);
		vbox->Add(m_pRenderView, 1, wxEXPAND | wxALL, 0);
		m_panelMain->SetSizer(vbox);

		this->Connect(ID_TIMER, wxEVT_TIMER, wxTimerEventHandler(EdFrame::OnTimer));

		m_pTimer =new wxTimer(this, ID_TIMER);
		m_pTimer->Start(TIMER_INTERVAL);
}

//-----------------------------------------------------------------------------
void EdFrame::Init()
{
		Com::GameConfig gc;
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
		delete m_pTimer;
		event.Skip();
}

//-----------------------------------------------------------------------------
void EdFrame::OnIdle( wxIdleEvent& event )
{
		event.Skip();
}

//-----------------------------------------------------------------------------
void EdFrame::OnTimer(wxTimerEvent& evt)
{
		if(m_pEditor)
				m_pEditor->Update();

		if(m_pRenderView)
				m_pRenderView->Update(evt.GetInterval()/1000.f);
}