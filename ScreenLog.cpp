#include "ScreenLog.h"
#include <string>
#include "SpriteFont.h"
#include "LotusSprite.h"
#include "SceneManager.h"
#include "SpriteFontManager.h"
ScreenLog* ScreenLog::InstancePtr = nullptr;

ScreenLog::ScreenLog()
{
	font = SpriteFontManager::Get(ScreenLogText);
}

void ScreenLog::privDelete()
{
	for (MessageCollection::iterator it = messages.begin(); it != messages.end(); it++)
	{
		delete& it->back();
		it->pop_back();
	}

	delete InstancePtr;

	InstancePtr = nullptr;



}

void ScreenLog::Add(char* A, ...)
{
	va_list args;

	va_start(args, A);
	vsprintf_s(Instance().DebugBuff, A, args);
	va_end(args);

	std::string s(Instance().DebugBuff);
	Instance().messages.push_back(s);

}

void ScreenLog::privRender()
{
	int offsetY = 0;
	for (MessageCollection::iterator it = messages.begin(); it != messages.end(); it++)
	{
		std::string s = *it;
		int offsetX = 0;
		for (unsigned int i = 0; i < it->length(); i++)
		{
			LotusSprite* tmp = font->GetGlyph(s[i]);
			tmp->SetPosition((float)this->anchorX + offsetX, (float)this->anchorY - (tmp->GetHeight() * offsetY));
			offsetX += (int)tmp->GetWidth();
			tmp->Render(SceneManager::GetCameraManager()->GetCurrent2DCamera());
		}
		offsetY++;
	}
	messages.clear();
}