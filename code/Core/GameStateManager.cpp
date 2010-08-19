////////////////////////////////////////////////////////////////////////////
//
//  Copyright (C) Justin 2010-.
// -------------------------------------------------------------------------
//  File name: GameStateManager.cpp
//  Created:   19-08-2010 by Dongjoon Kim
//
//////////////////////////////////////////////////////////////////////////// 

#include <Core/IGameStateManager.h>
#include <Core/IGameState.h>

#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/unordered_map.hpp>

namespace Core{

		//-----------------------------------------------------------------------------
		//!
		class GameStateManager : public IGameStateManager
		{
		public:
				//-----------------------------------------------------------------------------
				//!
				typedef boost::unordered_map<std::string, boost::shared_ptr<IGameState>> GameStateMap;

				//-----------------------------------------------------------------------------
				//!
				GameStateManager(){}

				//-----------------------------------------------------------------------------
				//!
				virtual ~GameStateManager()
				{
						while(!m_ActiveStates.empty())
						{
								m_ActiveStates.back()->Exit();
								m_ActiveStates.pop_back();
						}
				}

				//-----------------------------------------------------------------------------
				//!
				virtual void AddGameState(const char* strName, IGameState* pState)
				{
						m_States.insert(std::make_pair(std::string(strName), pState));
				}

				//-----------------------------------------------------------------------------
				//!
				virtual IGameState* FindByName(const char* strName)
				{
						GameStateMap::iterator itr = m_States.find(strName);
						if(itr != m_States.end())
						{
								return (itr->second).get();
						}
						else
						{
								return 0;
						}
				}

				//-----------------------------------------------------------------------------
				//!
				virtual void Change(IGameState* pState)
				{
						if(!m_ActiveStates.empty())
						{
								m_ActiveStates.back()->Exit();
								m_ActiveStates.pop_back();
						}

						m_ActiveStates.push_back(pState);
						m_ActiveStates.back()->Enter();
				}

				//-----------------------------------------------------------------------------
				//!
				virtual bool Push(IGameState* pState)
				{
						if(!m_ActiveStates.empty())
						{
								if(!m_ActiveStates.back()->Pause())
										return false;
						}

						m_ActiveStates.push_back(pState);
						m_ActiveStates.back()->Enter();

						return true;
				}

				//-----------------------------------------------------------------------------
				//!
				virtual void Pop()
				{
						if(!m_ActiveStates.empty())
						{
								m_ActiveStates.back()->Exit();
								m_ActiveStates.pop_back();
						}

						if(!m_ActiveStates.empty())
						{
								m_ActiveStates.back()->Resume();
						}
				}

				//-----------------------------------------------------------------------------
				//!
				virtual void Update(float timeDelta)
				{
						if(!m_ActiveStates.empty())
								m_ActiveStates.back()->Update(timeDelta);
				}

		protected:

				GameStateMap m_States;
				std::vector<IGameState*> m_ActiveStates;
		};

		//-----------------------------------------------------------------------------
		//!
		IGameStateManager* IGameStateManager::Create()
		{
				return new GameStateManager();
		}

} //Core