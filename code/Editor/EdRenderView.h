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

#include <Core/ICameraManipulator.h>
#include <OgreTimer.h>

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
		wxCoord m_lastX, m_lastY;

		Core::ICameraManipulator* m_pCamManipulator;

		Ogre::Timer m_timer;
		unsigned long m_lastTime;

		struct CamCommand
		{
				CamCommand():m_forward(0),m_backward(0),m_left(0),m_right(0){}
				float m_forward, m_backward;
				float m_right, m_left;

		}m_CamCommand;

		virtual void OnSize(wxSizeEvent& evt);
		virtual void OnEraseBackground(wxEraseEvent& evt);	
		virtual void OnClose(wxCloseEvent & evt);
		virtual void OnMouseMotion(wxMouseEvent & evt);
		virtual void OnKeyDown(wxKeyEvent& event);
		virtual void OnKeyUp(wxKeyEvent& event);
};