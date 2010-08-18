#include <EdApp.h>
#include <EdFrame.h>
#include <IEditor.h>

IMPLEMENT_APP(EdApp)

EdApp::EdApp()
{
}

EdApp::~EdApp()
{
}

bool EdApp::OnInit()
{
		EdFrame *frame = new EdFrame(NULL);
		frame->Show(true);
		SetTopWindow(frame);
		
		frame->Init();
		
		return true;
}
