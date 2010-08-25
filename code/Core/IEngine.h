////////////////////////////////////////////////////////////////////////////
//
//  Copyright (C) Justin 2010-.
// -------------------------------------------------------------------------
//  File name: IEngine.h
//  Created:   17-08-2010 by Dongjoon Kim
//
//////////////////////////////////////////////////////////////////////////// 

#pragma once

#include <Common/GameConfig.h>

namespace Core{

		//-----------------------------------------------------------------------------
		//!
		class IGrid;
		class ICameraManipulator;

		//-----------------------------------------------------------------------------
		//!
		class IEngine
		{
		public:
				//-----------------------------------------------------------------------------
				//!
				static IEngine* Create(const Com::GameConfig& gc);

				//-----------------------------------------------------------------------------
				//!
				virtual ~IEngine(){}

				//-----------------------------------------------------------------------------
				//!
				virtual bool Update() = 0;

				//-----------------------------------------------------------------------------
				//!
				virtual IGrid* CreateGrid() = 0;

				//-----------------------------------------------------------------------------
				//!
				virtual void OnRenderViewSize() = 0;

				//-----------------------------------------------------------------------------
				//!
				virtual ICameraManipulator* CreateCameraManipulator() = 0;
		};
}