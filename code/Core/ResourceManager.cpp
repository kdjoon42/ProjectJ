////////////////////////////////////////////////////////////////////////////
//
//  CryEngine Source File.
//  Copyright (C), Crytek, 1999-2010.
// -------------------------------------------------------------------------
//  File name: ResourceManager.cpp
//  Version:   v1.00
//  Created:   19-08-2010 by Dongjoon Kim
//  Description:
// -------------------------------------------------------------------------  
//  History:
//
//////////////////////////////////////////////////////////////////////////// 

#include <Core/IResourceManager.h>

#include <OgreResourceGroupManager.h>

#include <OgreRoot.h>

namespace Core{

		//-----------------------------------------------------------------------------
		//!
		class ResourceManager : public IResourceManager
		{
		public:

				//-----------------------------------------------------------------------------
				//!
				ResourceManager();

				//-----------------------------------------------------------------------------
				//!
				~ResourceManager();

		protected:
				//-----------------------------------------------------------------------------
				//!
				void RegisterLocations();

		};

		//////////////////////////////////////////////////////////////////////////
		//

		//-----------------------------------------------------------------------------
		IResourceManager* IResourceManager::Create()
		{
				return new ResourceManager();
		}

		//-----------------------------------------------------------------------------
		ResourceManager::ResourceManager()
		{
				RegisterLocations();
		}

		//-----------------------------------------------------------------------------
		ResourceManager::~ResourceManager()
		{

		}

		//-----------------------------------------------------------------------------
		void ResourceManager::RegisterLocations()
		{
				Ogre::ResourceGroupManager::getSingleton().addResourceLocation("../Data/Models", "FileSystem", "Common");

				
				Ogre::ResourceGroupManager::getSingleton().initialiseResourceGroup("Common");
				bool bExist = Ogre::ResourceGroupManager::getSingleton().resourceExists("Common", "ogrehead.mesh");

				Ogre::SceneManager* pSM = Ogre::Root::getSingleton().createSceneManager(Ogre::ST_GENERIC);
				Ogre::Entity* pEn = pSM->createEntity("ogrehead.mesh");

				int k=0;
				
				
		}


}//Core