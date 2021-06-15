#include "CollisionDeregistrationCommand.h"
#include "CollidableAttorney.h"

CollisionDeregistrationCommand::CollisionDeregistrationCommand(Collidable* cl)
	:ptrCol(cl)
{}


void CollisionDeregistrationCommand::Execute()
{
	CollidableAttorney::Deregistration::SceneDeregistration(this->ptrCol);

}