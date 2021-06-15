#ifndef _CollidableAttorney
#define _CollidableAttorney

#include "Collidable.h"

class CollidableAttorney
{
public:
	class GameLoop
	{
	private:
		friend class CollisionManager;
		friend class CollisionTestPairCommand;
		friend class CollisionTestSelfCommand;
		static CollisionVolumeBSphere* GetDefaultBSphere(Collidable* pMgr) { return pMgr->pBSphere; }
	};

public:
	class Registration
	{
		friend class CollisionRegistrationCommand;
		
	private:
		static void SceneRegistration(Collidable* pMgr) { pMgr->SceneRegistration(); }
		
	};
public:
	class Deregistration
	{
		friend class CollisionDeregistrationCommand;
		static void SceneDeregistration(Collidable* pMgr) { pMgr->SceneDeregistration(); }
	};
};

#endif _CollidableAttorney
