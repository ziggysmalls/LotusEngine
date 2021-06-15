#include "Collidable.h"
#include "CollisionRegistrationCommand.h"
#include "CollisionDeregistrationCommand.h"
#include "SceneManager.h"
#include "CollisionVolumeBSphere.h"
#include "CollisionVolumeAABB.h"
#include "CollisionVolumeOBB.h"
Collidable::Collidable()
	: currRegState(RegistrationState::RegStates::CURRENTLY_DEREGISTERED)
{
	this->pColVolume = nullptr;
	pRegistrationCmd = new CollisionRegistrationCommand(this);
	pDeregistrationCmd = new CollisionDeregistrationCommand(this);
	pColModel = nullptr;
	pBSphere = new CollisionVolumeBSphere();
	
}

void Collidable::SceneRegistration()
{
	assert(this->currRegState == RegistrationState::RegStates::PENDING_REGISTRATION);

	SceneAttorney::Registration::GetCollisionMgr()->GetColGroup(myID)->Register(this, pMyDeleteRef);

	this->currRegState = RegistrationState::RegStates::CURRENTLY_REGISTERED;

}

void Collidable::SceneDeregistration()
{
	assert(this->currRegState == RegistrationState::RegStates::PENDING_DEREGISTRATION);

	SceneAttorney::Registration::GetCollisionMgr()->GetColGroup(myID)->Deregister(pMyDeleteRef);

	this->currRegState = RegistrationState::RegStates::CURRENTLY_DEREGISTERED;

	

}

void Collidable::SubmitCollisionRegistration()
{
	assert(currRegState == RegistrationState::RegStates::CURRENTLY_DEREGISTERED);

	SceneAttorney::CommandSubmission::SubmitCommand(SceneManager::GetCurrentScene(), pRegistrationCmd);

	currRegState = RegistrationState::RegStates::PENDING_REGISTRATION;

}

void Collidable::SubmitCollisionDeregistration()
{
	assert(currRegState == RegistrationState::RegStates::CURRENTLY_REGISTERED);

	SceneAttorney::CommandSubmission::SubmitCommand(SceneManager::GetCurrentScene(), pDeregistrationCmd);

	currRegState = RegistrationState::RegStates::PENDING_DEREGISTRATION;

	
}

void Collidable::SetColliderModel(Model* mod, VolumeType vt)
{
	GetCV(vt);
	this->pColModel = mod;
}

void Collidable::UpdateCollisionData(const Matrix& mat)
{
	this->pBSphere->ComputeData(this->pColModel, mat);
	this->pColVolume->ComputeData(this->pColModel, mat);
}

const CollisionVolume& Collidable::GetCollisionVolume()
{
	return *this->pColVolume;
}

Collidable::~Collidable()
{

	delete pColVolume;
	delete pRegistrationCmd;
	delete pDeregistrationCmd;
	delete pBSphere;
}
const CollisionVolumeBSphere& Collidable::GetDefaultBSphere()
{
	return *this->pBSphere;
}

void Collidable::GetCV(VolumeType vt)
{
	switch (vt)
	{
	case VolumeType::BSPHERE:
		this->pColVolume = new CollisionVolumeBSphere();
		break;
	case VolumeType::AABB:
		this->pColVolume = new CollisionVolumeAABB();
		break;
	case VolumeType::OBB:
		this->pColVolume = new CollisionVolumeOBB();
	default:
		break;
	}

}