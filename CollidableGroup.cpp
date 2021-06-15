#include "CollidableGroup.h"
#include "CollisionVolumeAABB.h"
CollidableGroup::CollidableGroup()
{
	pColAABB = new CollisionVolumeAABB();
}
CollidableGroup::~CollidableGroup()
{
	delete pColAABB;
	pColAABB = nullptr;
}
void CollidableGroup::Register(Collidable* cl, CollidableCollectionRef& ref)
{
	ref = listColl.insert(listColl.end(), cl);
}

void CollidableGroup::Deregister(CollidableCollectionRef& ref)
{
	listColl.erase(ref);
}

const CollidableGroup::CollidableCollection& CollidableGroup::GetColliderCollection()
{
	return this->listColl;
}