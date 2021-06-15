#include "LotusSprite.h"
#include "GraphicsObject_Sprite.h"
#include "ShaderManager.h"
#include "ModelManager.h"
#include "ImageManager.h"
LotusSprite::LotusSprite()
{
	pGO_Sprite = nullptr;
}

LotusSprite::LotusSprite(std::string imgKey)
{
	pGO_Sprite = new GraphicsObject_Sprite(ModelManager::Get("Sprite"), ShaderManager::Get("SpriteRender"), ImageManager::Get(imgKey), ImageManager::Get(imgKey)->pImageRect);
}

void LotusSprite::Render(Camera* pCam)
{
	Scale.set(SCALE, this->scaleX, this->scaleY, 1.0f);
	RotZ.set(ROT_Z, this->angle);
	Trans.set(TRANS, pGO_Sprite->origPosX, pGO_Sprite->origPosY, 0.0f);

	world = Scale * RotZ * Trans;

	pGO_Sprite->SetWorld(world);

	pGO_Sprite->Render(pCam);
}

void LotusSprite::SetAngle(float a)
{
	this->angle = a;
}
void LotusSprite::SetCenter(float offsetX, float offsetY)
{
	this->centerX = offsetX;
	this->centerY = offsetY;
}
void LotusSprite::SetPosition(float x, float y)
{
	pGO_Sprite->origPosX = x;
	pGO_Sprite->origPosY = y;
}

void LotusSprite::SetScaleFactor(float scalex, float scaley)
{
	this->scaleX = scalex;
	this->scaleY = scaley;
}

void LotusSprite::SetScalePixel(float width, float height)
{
	this->scaleX = width / pGO_Sprite->origWidth;
	this->scaleY = height / pGO_Sprite->origHeight;
}

float LotusSprite::GetAngle()
{
	return this->angle;
}
float LotusSprite::GetHeight()
{
	return this->pGO_Sprite->origHeight;
}

float LotusSprite::GetWidth()
{
	return this->pGO_Sprite->origWidth;
}
LotusSprite::~LotusSprite()
{
	delete pGO_Sprite;
}

