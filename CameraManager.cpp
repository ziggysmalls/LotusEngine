#include "CameraManager.h"
#include "../LotusEngine.h"



CameraManager::CameraManager()
{
	// Default Camera Type Perspective
	this->defaultCamera = new Camera(Camera::Type::PERSPECTIVE_3D);
	this->defaultCamera->setViewport(0, 0, LotusEngine::GetWidth(), LotusEngine::GetHeight());
	this->defaultCamera->setPerspective(35.0f, float(LotusEngine::GetWidth()) / float(LotusEngine::GetHeight()), 1.0f, 5000.0f);

	// Default Camera Position and Orientation
	Vect up3DCam(0.0f, 1.0f, 0.0f);
	Vect pos3DCam(50.0f, 50.0f, 150.0f);
	Vect lookAt3DCam(0.0f, 0.0f, 0.0f);
	this->defaultCamera->setOrientAndPosition(up3DCam, lookAt3DCam, pos3DCam);
	this->defaultCamera->updateCamera();
	this->currentCamera = this->defaultCamera;

	// Default 2D camera

	this->default2DCamera = new Camera(Camera::Type::ORTHOGRAPHIC_2D);
	this->default2DCamera->setViewport(0, 0, LotusEngine::GetWidth(), LotusEngine::GetHeight());
	this->default2DCamera->setOrthographic(-0.5f * LotusEngine::GetWidth(), 0.5f * LotusEngine::GetWidth(),
		-0.5f * LotusEngine::GetHeight(), 0.5f * LotusEngine::GetHeight(), 1.0f, 1000.0f);

	// Orientation 2D Camera
	Vect up2DCam(0.0f, 1.0f, 0.0f);
	Vect pos2DCam(0.0f, 0.0f, 0.0f);
	Vect lookAt2DCam(0.0f, 0.0f, -1.0f);
	this->default2DCamera->setOrientAndPosition(up2DCam, lookAt2DCam, pos2DCam);
	this->current2DCamera = this->default2DCamera;
	this->default2DCamera->updateCamera();
}

Camera* CameraManager::GetCurrentCamera()
{
	return currentCamera;
}
Camera* CameraManager::GetCurrent2DCamera()
{
	return current2DCamera;
}
void CameraManager::SetCurrent2DCamera(Camera* new2dcam)
{
	this->current2DCamera = new2dcam;
}

void CameraManager::Update()
{
	this->currentCamera->updateCamera();
}
void CameraManager::Delete() 
{
	if (currentCamera == defaultCamera) 
		delete currentCamera;
	else
	{
		delete currentCamera;
		delete defaultCamera;
	}
}
CameraManager::~CameraManager()
{
	if (currentCamera == defaultCamera)
		delete currentCamera;
	else
	{
		delete currentCamera;
		delete defaultCamera;
	}
	if (current2DCamera == default2DCamera)
		delete current2DCamera;
	else
	{
		delete current2DCamera;
		delete default2DCamera;
	}
}

void CameraManager::SetCurrentCamera(Camera* newcam)
{
	this->currentCamera = newcam;
}

void CameraManager::setPerspective(const float FieldOfView_Degs, const float AspectRatio, const float NearDist, const float FarDist)
{
	this->currentCamera->setPerspective(FieldOfView_Degs, AspectRatio, NearDist, FarDist);
}
void CameraManager::setOrthographic(const float xMin, const float xMax, const float yMin, const float yMax, const float zMin, const float zMax)
{
	this->currentCamera->setOrthographic(xMin, xMax, yMin, yMax, zMin, zMax);
}
void CameraManager::setViewport(const int inX, const int inY, const int width, const int height)
{
	this->currentCamera->setViewport(inX, inY, width, height);
}
void CameraManager::setOrientAndPosition(const Vect& Up_vect, const Vect& inLookAt_pt, const Vect& pos_pt)
{
	this->currentCamera->setOrientAndPosition(Up_vect, inLookAt_pt, pos_pt);
}
