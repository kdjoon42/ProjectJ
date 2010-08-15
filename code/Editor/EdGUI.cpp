///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 17 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "EdViewPanel.h"

#include "EdGUI.h"

///////////////////////////////////////////////////////////////////////////

Frame::Frame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizerTop;
	bSizerTop = new wxBoxSizer( wxVERTICAL );
	
	m_splitterVert = new wxSplitterWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitterVert->SetSashGravity( 1 );
	m_splitterVert->Connect( wxEVT_IDLE, wxIdleEventHandler( Frame::m_splitterVertOnIdle ), NULL, this );
	
	m_panelLeft = new wxPanel( m_splitterVert, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxDOUBLE_BORDER|wxTAB_TRAVERSAL );
	wxBoxSizer* bSizerLeft;
	bSizerLeft = new wxBoxSizer( wxHORIZONTAL );
	
	m_splitterHoriz = new wxSplitterWindow( m_panelLeft, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D|wxDOUBLE_BORDER );
	m_splitterHoriz->SetSashGravity( 1 );
	m_splitterHoriz->Connect( wxEVT_IDLE, wxIdleEventHandler( Frame::m_splitterHorizOnIdle ), NULL, this );
	
	m_panelMain = new EdViewPanel( m_splitterHoriz, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxDOUBLE_BORDER|wxTAB_TRAVERSAL );
	m_panelBottom = new wxPanel( m_splitterHoriz, wxID_ANY, wxDefaultPosition, wxSize( -1,100 ), wxDOUBLE_BORDER|wxTAB_TRAVERSAL );
	m_splitterHoriz->SplitHorizontally( m_panelMain, m_panelBottom, 559 );
	bSizerLeft->Add( m_splitterHoriz, 1, wxEXPAND, 0 );
	
	m_panelLeft->SetSizer( bSizerLeft );
	m_panelLeft->Layout();
	bSizerLeft->Fit( m_panelLeft );
	m_panelRight = new wxPanel( m_splitterVert, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizerRight;
	bSizerRight = new wxBoxSizer( wxVERTICAL );
	
	m_notebook = new wxNotebook( m_panelRight, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	bSizerRight->Add( m_notebook, 1, wxEXPAND | wxALL, 5 );
	
	m_panelRight->SetSizer( bSizerRight );
	m_panelRight->Layout();
	bSizerRight->Fit( m_panelRight );
	m_splitterVert->SplitVertically( m_panelLeft, m_panelRight, -300 );
	bSizerTop->Add( m_splitterVert, 1, wxALIGN_BOTTOM|wxEXPAND, 5 );
	
	this->SetSizer( bSizerTop );
	this->Layout();
	m_statusBar = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
	m_menubar = new wxMenuBar( 0 );
	m_menuFile = new wxMenu();
	m_menubar->Append( m_menuFile, wxT("File") ); 
	
	this->SetMenuBar( m_menubar );
	
	m_toolBar = this->CreateToolBar( wxTB_HORIZONTAL, wxID_ANY ); 
	m_toolBar->Realize();
	
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_IDLE, wxIdleEventHandler( Frame::OnIdle ) );
}

Frame::~Frame()
{
	// Disconnect Events
	this->Disconnect( wxEVT_IDLE, wxIdleEventHandler( Frame::OnIdle ) );
	
}

ViewPanel::ViewPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	
	// Connect Events
	this->Connect( wxEVT_SIZE, wxSizeEventHandler( ViewPanel::OnSize ) );
}

ViewPanel::~ViewPanel()
{
	// Disconnect Events
	this->Disconnect( wxEVT_SIZE, wxSizeEventHandler( ViewPanel::OnSize ) );
	
}
