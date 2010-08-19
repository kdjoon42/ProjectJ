////////////////////////////////////////////////////////////////////////////
//
//  Copyright (C) Justin 2010-.
// -------------------------------------------------------------------------
//  File name: IGameState.h
//  Created:   19-08-2010 by Dongjoon Kim
//
//////////////////////////////////////////////////////////////////////////// 

#pragma once

namespace Core{

		class IGameStateManager;
		
		//-----------------------------------------------------------------------------
		//!
		class IGameState
		{
		public:
				//-----------------------------------------------------------------------------
				//!
				virtual ~IGameState(){}

				//-----------------------------------------------------------------------------
				//!
				virtual void Enter() = 0;

				//-----------------------------------------------------------------------------
				//!
				virtual void Exit() = 0;

				//-----------------------------------------------------------------------------
				//!
				virtual bool Pause() = 0;

				//-----------------------------------------------------------------------------
				//!
				virtual void Resume() = 0;
				
				//-----------------------------------------------------------------------------
				//!
				virtual void Update(float timeDelta) = 0;

				//-----------------------------------------------------------------------------
				//!
				virtual IGameStateManager* GetParent() { return m_pParent; }

				//-----------------------------------------------------------------------------
				//!
				virtual void SetParent(IGameStateManager* pParent) { m_pParent = pParent; }
				
		protected:
				//-----------------------------------------------------------------------------
				//!
				IGameState():m_pParent(0){}

				IGameStateManager* m_pParent;
		};


}//Core

#define DECLARE_GAEMSTATE_CLASS(T)																					\
		static void Create(Core::IGameStateManager* parent, const char* name)		\
{																																						\
		T* myState = new T();																										\
		myState->SetParent(parent);																							\
		parent->AddGameState(name, myState);																		\
}																																		