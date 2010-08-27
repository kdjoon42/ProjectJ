////////////////////////////////////////////////////////////////////////////
//
//  Copyright (C) Justin 2010-.
// -------------------------------------------------------------------------
//  File name: EdRenderView.cpp
//  Created:   18-08-2010 by Dongjoon Kim
//
//////////////////////////////////////////////////////////////////////////// 

#include <EdRenderView.h>
#include <Editor/IEditor.h>
#include <Main/IGame.h>
#include <Core/IEngine.h>

IMPLEMENT_DYNAMIC_CLASS(EdRenderView, wxControl);

//-----------------------------------------------------------------------------
EdRenderView::EdRenderView(wxWindow *parent, wxWindowID id, const wxPoint& pos,
													 const wxSize& size, long style, const wxValidator& validator,
													 const wxString& name)
													 :wxControl(parent, id, pos, size, style, validator, name)
													 ,m_pCamManipulator(0),m_lastX(0),m_lastY(0),m_lastTime(0)

{
		this->Connect(wxEVT_SIZE, wxSizeEventHandler(EdRenderView::OnSize));
		this->Connect(wxEVT_ERASE_BACKGROUND, wxEraseEventHandler(EdRenderView::OnEraseBackground));
		this->Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(EdRenderView::OnClose));
		this->Connect(wxEVT_MOTION,wxMouseEventHandler(EdRenderView::OnMouseMotion));
		this->Connect(wxEVT_MOUSEWHEEL,wxMouseEventHandler(EdRenderView::OnMouseMotion));
		this->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(EdRenderView::OnKeyDown));
		this->Connect(wxEVT_KEY_UP, wxKeyEventHandler(EdRenderView::OnKeyUp));
		
		m_timer.reset();
		
}

//-----------------------------------------------------------------------------
EdRenderView::~EdRenderView()
{
}

//-----------------------------------------------------------------------------
void EdRenderView::OnSize(wxSizeEvent& evt)
{
		Ed::IEditor::Instance().GetGame()->GetEngine()->OnRenderViewSize();

		Refresh();
}

//-----------------------------------------------------------------------------
void EdRenderView::OnEraseBackground(wxEraseEvent& evt)
{
		wxControl::OnEraseBackground(evt);
}

//-----------------------------------------------------------------------------
void EdRenderView::OnClose(wxCloseEvent & evt)
{
}

//-----------------------------------------------------------------------------
void EdRenderView::OnMouseMotion(wxMouseEvent & evt)
{
		if(!m_pCamManipulator)
		{
				m_pCamManipulator = Ed::IEditor::Instance().GetCamManipulator();
		}

		if(wxWindow::FindFocus() != this)
				return;

		wxCoord deltaX = evt.GetX() - m_lastX;
		wxCoord deltaY = evt.GetY() - m_lastY;

		m_lastX = evt.GetX();
		m_lastY = evt.GetY();

		if(evt.Dragging())
		{
				if(evt.LeftIsDown())
				{
						m_pCamManipulator->Yaw(-deltaX*0.001f);
						m_pCamManipulator->Pitch(-deltaY*0.001f);
				}
				else if(evt.RightIsDown())
				{
						m_pCamManipulator->Pan(-deltaX*0.01f, deltaY*0.01f);
				}
		}

		if(evt.GetWheelDelta()!=0)
		{
				int deltaZ = evt.GetWheelDelta()*evt.GetWheelRotation();
				m_pCamManipulator->Zoom(deltaZ*0.0005f);
		}

}

//-----------------------------------------------------------------------------
bool EdRenderView::Show(bool show)
{
		return wxControl::Show(show);
}

//-----------------------------------------------------------------------------
void EdRenderView::OnKeyDown(wxKeyEvent& event)
{
		if(event.GetKeyCode()=='W')
		{
				m_CamCommand.m_forward = 1.f;
		}
		if(event.GetKeyCode()=='S')
		{
				m_CamCommand.m_backward = -1.f;
		}
		if(event.GetKeyCode()=='A')
		{
				m_CamCommand.m_left =-1.f;
		}
		if(event.GetKeyCode()=='D')
		{
				m_CamCommand.m_right =1.f;
		}
}

//-----------------------------------------------------------------------------
void EdRenderView::OnKeyUp(wxKeyEvent& event)
{
		if(event.GetKeyCode()=='W')
		{
				m_CamCommand.m_forward = 0.f;
		}
		if(event.GetKeyCode()=='S')
		{
				m_CamCommand.m_backward = 0.f;
		}
		if(event.GetKeyCode()=='A')
		{
				m_CamCommand.m_left = 0.f;
		}
		if(event.GetKeyCode()=='D')
		{
				m_CamCommand.m_right = 0.f;
		}
}

//-----------------------------------------------------------------------------
void EdRenderView::Update(float deltaTime)
{
		float speed = 5.f;

		if(m_pCamManipulator)
				m_pCamManipulator->Pan
				(
						deltaTime*speed*(m_CamCommand.m_left + m_CamCommand.m_right),
						deltaTime*speed*(m_CamCommand.m_forward + m_CamCommand.m_backward)
				);
}