
#pragma once

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include <boost/scoped_ptr.hpp>

namespace Ed{ class IEditor; }

class EdApp : public wxApp
{
public:
    EdApp();
    virtual ~EdApp();
    virtual bool OnInit();

	Ed::IEditor* GetEditor() { return m_pEditor.get(); }

protected:

	boost::scoped_ptr<Ed::IEditor> m_pEditor;
};

DECLARE_APP(EdApp)
