
#pragma once

#include <wx/wx.h>
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
