#ifndef _CollidableGroup
#define _CollidableGroup
#include <list>
class CollisionVolumeAABB;
class Collidable;
class CollidableGroup : public Align16
{
public:
	using CollidableCollection = std::list< Collidable*>;

	using CollidableCollectionRef = CollidableCollection::iterator;

	CollidableGroup();
	~CollidableGroup();
	CollidableGroup(const CollidableGroup&) = delete;
	CollidableGroup& operator=(const CollidableGroup&) = delete;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Registers this object. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	///
	/// <param name="cl"> 	[in,out] If non-null, the cl. </param>
	/// <param name="ref">	[in,out] The reference. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void Register(Collidable* cl, CollidableCollectionRef& ref);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Deregisters this object. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	///
	/// <param name="ref">	[in,out] The reference. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void Deregister(CollidableCollectionRef& ref);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets collider collection. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	///
	/// <returns>	The collider collection. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	const CollidableCollection& GetColliderCollection();

private:
	CollidableCollection listColl;
	CollisionVolumeAABB* pColAABB;

};


#endif _CollidableGroup