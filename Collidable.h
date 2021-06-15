#ifndef _Collidable
#define _Collidable

#include "CollisionManager.h"
#include "SceneAttorney.h"
#include "CollidableGroup.h"	
#include "CollisionVolume.h"
#include "CollisionVolumeBSphere.h"
#include "RegistrationState.h"

class CollisionRegistrationCommand;
class CollisionDeregistrationCommand;
class Collidable
{
	friend class CollidableAttorney;
public:
	enum class VolumeType{BSPHERE, AABB, OBB};
private:
	
	CollisionManager::LETypeID myID = CollisionManager::LEID_UNDEFINED;

	// used for fast delete on manager
	CollidableGroup::CollidableCollectionRef pMyDeleteRef;
	RegistrationState::RegStates currRegState;
	CollisionRegistrationCommand* pRegistrationCmd;
	CollisionDeregistrationCommand* pDeregistrationCmd;


	// Scene Level Functions
	void SceneRegistration();
	void SceneDeregistration();

	// Collision Data
	Model* pColModel;
	CollisionVolume* pColVolume;
	

protected:
	Collidable();
	Collidable(const Collidable&) = delete;
	Collidable& operator=(const Collidable&) = delete;
	virtual ~Collidable();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \ingroup COLLISIONS
	/// <summary>	Sets collidable group. </summary>
	///
	/// <typeparam name="C">	Type of the c. </typeparam>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	template < typename C>
	void SetCollidableGroup()
	{
		myID = SceneAttorney::Registration::GetCollisionMgr()->GetTypeID<C>();
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \ingroup COLLISION
	/// <summary>	User Functions. </summary>
	///
	/// <remarks>	Ezequ, 3/10/2021. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void SubmitCollisionRegistration();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \ingroup COLLISION
	/// <summary>	Submit collision deregistration. </summary>
	///
	/// <remarks>	Ezequ, 3/10/2021. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void SubmitCollisionDeregistration();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \ingroup COLLISION
	/// <summary>	Sets collider model. </summary>
	///
	/// <remarks>	Ezequ, 3/10/2021. </remarks>
	///
	/// <param name="mod">	[in,out] If non-null, the modifier. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void SetColliderModel(Model* mod, VolumeType vt);

	

	void UpdateCollisionData(const Matrix& mat);
	void GetCV(VolumeType vt);
	CollisionVolumeBSphere* pBSphere;

public:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \ingroup COLLISION
	/// <summary>	this method is called whenever two collidable objects registered in the scene collide. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/10/2021. </remarks>
	///
	/// <param name="cl">	[in,out] If non-null, the cl. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void Collision(Collidable* cl) { cl; };
	virtual void CollisionTerrain() {};
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \ingroup COLLISION
	/// <summary>	Gets the Bounding sphere of the collidable. </summary>
	///
	/// <remarks>	Ezequ, 3/10/2021. </remarks>
	///
	/// <returns>	The sphere. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	const CollisionVolumeBSphere& GetDefaultBSphere();
	const CollisionVolume& GetCollisionVolume();

};


#endif _Collidable