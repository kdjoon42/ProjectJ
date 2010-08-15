#include "EdFrame.h"
#include <IEditor.h>
#include <EdViewPanel.h>

EdFrame::EdFrame( wxWindow* parent )
:
Frame( parent )
{	
}

void EdFrame::Init(Ed::IEditor* pEditor)
{
	if(pEditor)
	{
		pEditor->Init((HWND)(m_panelMain->GetHandle()));
	}
}