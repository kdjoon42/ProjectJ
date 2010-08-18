////////////////////////////////////////////////////////////////////////////
//
//  Copyright (C) Justin 2010-.
// -------------------------------------------------------------------------
//  File name: EdRenderView.cpp
//  Created:   18-08-2010 by Dongjoon Kim
//
//////////////////////////////////////////////////////////////////////////// 

#include <EdRenderView.h>

IMPLEMENT_DYNAMIC_CLASS(EdRenderView, wxControl);

//-----------------------------------------------------------------------------
EdRenderView::EdRenderView(wxWindow *parent, wxWindowID id, const wxPoint& pos,
													 const wxSize& size, long style, const wxValidator& validator,
													 const wxString& name)
													 :wxControl(parent, id, pos, size, style, validator, name)

{
		this->Connect(wxEVT_SIZE, wxSizeEventHandler(EdRenderView::OnSize));
		this->Connect(wxEVT_ERASE_BACKGROUND, wxEraseEventHandler(EdRenderView::OnEraseBackground));
		this->Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(EdRenderView::OnClose));
		this->Connect(wxEVT_MOTION,wxMouseEventHandler(EdRenderView::OnMouseMotion));
}

//-----------------------------------------------------------------------------
EdRenderView::~EdRenderView()
{

}

//-----------------------------------------------------------------------------
void EdRenderView::OnSize(wxSizeEvent& evt)
{
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

}

//-----------------------------------------------------------------------------
bool EdRenderView::Show(bool show)
{
		return wxControl::Show(show);
}