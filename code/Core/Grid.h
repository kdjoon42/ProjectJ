////////////////////////////////////////////////////////////////////////////
//
//  Copyright (C) Justin 2010-.
// -------------------------------------------------------------------------
//  File name: Grid.h
//  Created:   24-08-2010 by Dongjoon Kim
//
//////////////////////////////////////////////////////////////////////////// 

#pragma once

#include <Core/IGrid.h>
#include <OgreSceneManager.h>
#include <OgreMaterialManager.h>
#include <OgreMaterial.h>
#include <OgreManualObject.h>

#define GRID_MATERIAL_NAME "GridMaterial"

namespace Core{

		//-----------------------------------------------------------------------------
		//!
		class Grid : public IGrid
		{
		public:
				//-----------------------------------------------------------------------------
				//!
				Grid(Ogre::SceneManager* pSenceManager)
						:m_pSceneManager(pSenceManager)
				{
						m_pGrid = m_pSceneManager->createManualObject("GridObject");
						m_pNode = m_pSceneManager->getRootSceneNode()->createChildSceneNode("GridNode");
						Ogre::MaterialManager &matMgr = Ogre::MaterialManager::getSingleton();

						Ogre::MaterialPtr pMaterial = matMgr.create(
								GRID_MATERIAL_NAME,Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);

						pMaterial->setLightingEnabled(false);
						pMaterial->setSceneBlending(Ogre::SBT_TRANSPARENT_ALPHA);
				}

				//-----------------------------------------------------------------------------
				//!
				~Grid()
				{
						Ogre::MaterialManager &matMgr = Ogre::MaterialManager::getSingleton();
						matMgr.remove(GRID_MATERIAL_NAME);

						m_pSceneManager->destroyManualObject(m_pGrid);
						m_pGrid = 0;
						m_pSceneManager->destroySceneNode(m_pNode);
						m_pNode = 0;
				}

				//-----------------------------------------------------------------------------
				//!
				void Initialze(float size, float cellSize)
				{
						int numLines = (int)( size / cellSize) + 1;
						float worldSize = (float)numLines*cellSize;

						m_pGrid->estimateVertexCount(4*numLines);
						m_pGrid->begin(GRID_MATERIAL_NAME, Ogre::RenderOperation::OT_LINE_LIST);

						float worldLeft = -worldSize/2.f;
									

				}
				

		protected:
				
				Ogre::SceneManager* m_pSceneManager;
				Ogre::ManualObject* m_pGrid;
				Ogre::SceneNode* m_pNode;
		};

}//Core