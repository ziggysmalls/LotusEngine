#include "SpriteString.h"
#include "SceneManager.h"

SpriteString::SpriteString()
{
	posx = 0;
	posy = 0;
	height = 0;
	width = 0;
	sfont = nullptr;
}

SpriteString::SpriteString(const SpriteFont&)
{
	posx = 0;
	posy = 0;
	height = 0;
	width = 0;
	sfont = nullptr;

}

SpriteString::SpriteString(SpriteFont* sf, std::string s, int x, int y)
	:sfont(sf), posx(x), posy(y)
{
	for (unsigned int i = 0; i < s.length(); i++)
	{
		glyphs.insert(glyphs.end(), sf->GetGlyph(s[i]));
	}
	height = (int)sf->GetHeight();
	width = (int)sf->GetWidth();
}

int SpriteString::GetHeight()
{
	return this->height;
}

int SpriteString::GetWidth()
{
	return this->width;
}

void SpriteString::Render()
{
	int i = 0;
	for (GlypCollection::iterator it = glyphs.begin(); it != glyphs.end(); it++)
	{
		LotusSprite* tmp = *it;
		tmp->SetPosition((float)this->posx + (sfont->GetWidth() * i), (float)this->posy);
		i++;
		tmp->Render(SceneManager::GetCameraManager()->GetCurrent2DCamera());
	}

}

void SpriteString::Set(int x, int y)
{
	this->posx = x;
	this->posy = y;
}

void SpriteString::Set(SpriteFont* sf, std::string s, int x, int y)
{
	this->sfont = sf;
	this->posx = x;
	this->posy = y;
}