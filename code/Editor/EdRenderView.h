////////////////////////////////////////////////////////////////////////////
//
//  Copyright (C) Justin 2010-.
// -------------------------------------------------------------------------
//  File name: EdRenderView.h
//  Created:   18-08-2010 by Dongjoon Kim
//
//////////////////////////////////////////////////////////////////////////// 

#pragma once

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

class EdRenderView : public wxControl
{
public:

		DECLARE_DYNAMIC_CLASS(EdRenderView);

		//-----------------------------------------------------------------------------
		//!
		EdRenderView(){}

		//-----------------------------------------------------------------------------
		//!
		EdRenderView(wxWindow *parent, wxWindowID id,
				const wxPoint& pos = wxDefaultPosition,
				const wxSize& size = wxDefaultSize, long style = 0,
				const wxValidator& validator = wxDefaultValidator,
				const wxString& name = wxControlNameStr);

		//-----------------------------------------------------------------------------
		//!
		~EdRenderView();

		//-----------------------------------------------------------------------------
		//!
		virtual bool Show(bool show = true);

protected:

		virtual void OnSize(wxSizeEvent& evt);
		virtual void OnEraseBackground(wxEraseEvent& evt);	
		virtual void OnClose(wxCloseEvent & evt);
		virtual void OnMouseMotion(wxMouseEvent & evt);

};