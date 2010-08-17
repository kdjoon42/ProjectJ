///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __EdGUI__
#define __EdGUI__

class EdViewPanel;

#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/splitter.h>
#include <wx/sizer.h>
#include <wx/notebook.h>
#include <wx/statusbr.h>
#include <wx/menu.h>
#include <wx/toolbar.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class Frame
///////////////////////////////////////////////////////////////////////////////
class Frame : public wxFrame 
{
	private:
	
	protected:
		wxSplitterWindow* m_splitterVert;
		wxPanel* m_panelLeft;
		wxSplitterWindow* m_splitterHoriz;
		EdViewPanel* m_panelMain;
		wxPanel* m_panelBottom;
		wxPanel* m_panelRight;
		wxNotebook* m_notebook;
		wxStatusBar* m_statusBar;
		wxMenuBar* m_menubar;
		wxMenu* m_menuFile;
		wxToolBar* m_toolBar;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnIdle( wxIdleEvent& event ) { event.Skip(); }
		
	
	public:
		
		Frame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Editor"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1024,768 ), long style = wxDEFAULT_FRAME_STYLE|wxRESIZE_BORDER|wxSYSTEM_MENU|wxTAB_TRAVERSAL );
		~Frame();
		
		void m_splitterVertOnIdle( wxIdleEvent& )
		{
			m_splitterVert->SetSashPosition( -300 );
			m_splitterVert->Disconnect( wxEVT_IDLE, wxIdleEventHandler( Frame::m_splitterVertOnIdle ), NULL, this );
		}
		
		void m_splitterHorizOnIdle( wxIdleEvent& )
		{
			m_splitterHoriz->SetSashPosition( 559 );
			m_splitterHoriz->Disconnect( wxEVT_IDLE, wxIdleEventHandler( Frame::m_splitterHorizOnIdle ), NULL, this );
		}
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class ViewPanel
///////////////////////////////////////////////////////////////////////////////
class ViewPanel : public wxPanel 
{
	private:
	
	protected:
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSize( wxSizeEvent& event ) { event.Skip(); }
		
	
	public:
		
		ViewPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 494,291 ), long style = wxTAB_TRAVERSAL );
		~ViewPanel();
	
};

#endif //__EdGUI__
