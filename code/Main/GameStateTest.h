////////////////////////////////////////////////////////////////////////////
//
//  Copyright (C) Justin 2010-.
// -------------------------------------------------------------------------
//  File name: GameStateTest.h
//  Created:   19-08-2010 by Dongjoon Kim
//
//////////////////////////////////////////////////////////////////////////// 

#pragma once

#include <Core/IGameState.h>
#include <Core/IGameStateManager.h>

namespace Main
{

		//-----------------------------------------------------------------------------
		class GameStateTest : public Core::IGameState
		{
		public:
				DECLARE_GAEMSTATE_CLASS(GameStateTest);

				//-----------------------------------------------------------------------------
				//!
				virtual void Enter()
				{

				}

				//-----------------------------------------------------------------------------
				//!
				virtual void Exit()
				{

				}

				//-----------------------------------------------------------------------------
				//!
				virtual bool Pause()
				{
						return true;
				}

				//-----------------------------------------------------------------------------
				//!
				virtual void Resume()
				{

				}

				//-----------------------------------------------------------------------------
				//!
				virtual void Update(float timeDelta)
				{

				}
		};

}//Main