#include "EdViewPanel.h"
#include "EdApp.h"
#include "EdRenderView.h"

EdViewPanel::EdViewPanel( wxWindow* parent )
:ViewPanel( parent )
{

}

EdViewPanel::EdViewPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style)
:ViewPanel(parent, id, pos, size, style)
{
		//m_pRenderView = new EdRenderView(this, wxID_ANY);
		//wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
		//sizer->Add(m_pRenderView, 1, 0, 0);
		//SetSizer(sizer);
}

void EdViewPanel::OnSize( wxSizeEvent& event )
{
		event.Skip();
}