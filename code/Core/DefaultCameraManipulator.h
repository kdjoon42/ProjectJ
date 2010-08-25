////////////////////////////////////////////////////////////////////////////
//
//  Copyright (C) Justin 2010-.
// -------------------------------------------------------------------------
//  File name: DefaultCameraManipulator.h
//  Created:   25-08-2010 by Dongjoon Kim
//
//////////////////////////////////////////////////////////////////////////// 

#pragma once

#include <Core/ICameraManipulator.h>

namespace Core{

		//-----------------------------------------------------------------------------
		//!
		class DefaultCameraManipulator : public ICameraManipulator
		{
		public:
				//-----------------------------------------------------------------------------
				//!
				DefaultCameraManipulator(Ogre::Camera* pCamera):m_pCamera(pCamera)
				{
						m_pCamera->setNearClipDistance(1.f);
						m_pCamera->setOrientation(Ogre::Quaternion(Ogre::Degree(-90), Ogre::Vector3::UNIT_X));
						m_pCamera->setFixedYawAxis(true, Ogre::Vector3::UNIT_Z);
				}

				//-----------------------------------------------------------------------------
				//!
				~DefaultCameraManipulator()
				{
				}

				//-----------------------------------------------------------------------------
				//!
				void Set(const Ogre::Vector3& pos, const Ogre::Vector3& lookAt)
				{
						m_pCamera->setPosition(pos);
						m_pCamera->lookAt(lookAt);
				}

				//-----------------------------------------------------------------------------
				//!
				void Yaw(float radian)
				{
						m_pCamera->yaw(Ogre::Radian(radian));
				}

				//-----------------------------------------------------------------------------
				//!
				void Pitch(float radian)
				{
						m_pCamera->pitch(Ogre::Radian(radian));
				}

				//-----------------------------------------------------------------------------
				//!
				void Pan(float deltaX, float deltaY)
				{
						Ogre::Vector3 vFor = m_pCamera->getDirection();
						vFor.z = 0.f;
						vFor.normalise();
						Ogre::Vector3 vSide = m_pCamera->getRight();
						vSide.z = 0.f;
						vSide.normalise();

						Ogre::Vector3 vDisp = vFor*deltaY + vSide*deltaX;
						m_pCamera->move(vDisp);
				}

				//-----------------------------------------------------------------------------
				//!
				void Zoom(float deltaZ)
				{
						m_pCamera->moveRelative(Ogre::Vector3(0.f,0.f, deltaZ));
				}

		protected:
				
				Ogre::Camera* m_pCamera;
		};

}//Core