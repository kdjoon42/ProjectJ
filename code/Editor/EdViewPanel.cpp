#include "EdViewPanel.h"
#include "EdApp.h"

EdViewPanel::EdViewPanel( wxWindow* parent )
:ViewPanel( parent )
{

}

EdViewPanel::EdViewPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style)
:ViewPanel(parent, id, pos, size, style)
{
}

void EdViewPanel::OnSize( wxSizeEvent& event )
{
	int k=0;
}