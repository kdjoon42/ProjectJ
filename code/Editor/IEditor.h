

#pragma once

#include <Windows.h>

namespace Ed{

	class IEditor
	{
	public:

		static IEditor* Create();

		virtual ~IEditor(){}

		virtual bool Init(HWND hWnd) = 0;
	};

}//Ed