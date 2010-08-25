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
						float worldSize = (float)(int)( size / cellSize)*cellSize;

						m_pGrid->estimateVertexCount(4*numLines);
						m_pGrid->begin(GRID_MATERIAL_NAME, Ogre::RenderOperation::OT_LINE_LIST);

						float worldLeft = -worldSize/2.f;
						float worldRight = worldSize/2.f;
						float worldBottom = worldLeft;
						float worldTop = worldRight;

						Ogre::ColourValue color(0.7f,0.7f,0.7f,0.7f);

						float x = worldLeft;
						while(x<=worldRight)
						{								
								m_pGrid->position(x,worldBottom,0);
								m_pGrid->colour(x==0.f? Ogre::ColourValue(1.f,0,0,0.7f) : color);
								m_pGrid->position(x,worldTop,0);
								m_pGrid->colour(x==0.f? Ogre::ColourValue(1.f,0,0,0.7f) : color);

								x+=cellSize;
						}

						float y = worldBottom;
						while(y<=worldTop)
						{
								m_pGrid->position(worldLeft, y, 0);
								m_pGrid->colour(y==0.f? Ogre::ColourValue(0.f,1,0,0.7f) : color);
								m_pGrid->position(worldRight, y, 0);
								m_pGrid->colour(y==0.f? Ogre::ColourValue(0.f,1,0,0.7f) : color);
								
								y+=cellSize;
						}

						m_pGrid->end();

						m_pNode->attachObject(m_pGrid);
				}
				

		protected:
				
				Ogre::SceneManager* m_pSceneManager;
				Ogre::ManualObject* m_pGrid;
				Ogre::SceneNode* m_pNode;
		};

}//Core