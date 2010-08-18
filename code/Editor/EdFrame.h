#ifndef __EdFrame__
#define __EdFrame__

/**
@file
Subclass of Frame, which is generated by wxFormBuilder.
*/

#include "EdGUI.h"

//// end generated include

class EdRenderView;

namespace Ed{ class IEditor; }

/** Implementing Frame */
class EdFrame : public Frame
{
	public:
		/** Constructor */
		EdFrame( wxWindow* parent );
	//// end generated class members

		void Init();
		void OnClose( wxCloseEvent& event );
		void OnIdle( wxIdleEvent& event );

protected:

		EdRenderView* m_pRenderView;
		Ed::IEditor* m_pEditor;
};

#endif // __EdFrame__
