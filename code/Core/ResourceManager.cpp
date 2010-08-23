////////////////////////////////////////////////////////////////////////////
//
//  Copyright (C) Justin 2010-.
// -------------------------------------------------------------------------
//  File name: ResourceManager.cpp
//  Created:   23-08-2010 by Dongjoon Kim
//
//////////////////////////////////////////////////////////////////////////// 


#include <Core/IResourceManager.h>

#include <OgreResourceGroupManager.h>
#include <OgreConfigFile.h>

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
				void Initialize();

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
				Initialize();
		}

		//-----------------------------------------------------------------------------
		ResourceManager::~ResourceManager()
		{

		}

		//-----------------------------------------------------------------------------
		void ResourceManager::Initialize()
		{
				Ogre::ConfigFile cf;
				cf.load("resources.cfg");

				Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();
				Ogre::String sec, type, arch;

				while (seci.hasMoreElements())
				{
						sec = seci.peekNextKey();
						Ogre::ConfigFile::SettingsMultiMap* settings = seci.getNext();
						Ogre::ConfigFile::SettingsMultiMap::iterator i;

						for (i = settings->begin(); i != settings->end(); i++)
						{
								type = i->first;
								arch = i->second;
								Ogre::ResourceGroupManager::getSingleton().addResourceLocation(arch, type, sec);
						}
				}

				Ogre::TextureManager::getSingleton().setDefaultNumMipmaps(5);
				Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
		}

}//Core