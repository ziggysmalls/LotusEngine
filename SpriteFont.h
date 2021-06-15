// SpriteFont

#ifndef _SpriteFont
#define _SpriteFont

#include <string>
#include <map>
#include <xmllite.h>
class Texture;
class LotusSprite;
class SpriteFont
{
public:
	using Key = int;
	using Glyph = LotusSprite; // your sprite class;

private:
	float spaceTile = 16.0f;
	float heightTile = 6.0f;

	std::string TexKey;
	std::string FileExtension = ".tga";
	std::string Name;
	Texture* FontTexture;
	using FontMap = std::map< Key, Glyph* >;
	FontMap fontmap;

	// Parse the XML file
	void XMLtoCollection(std::string filename);

	// Tool: Reads & converts an XML attribute into an int
	void ElementTextToInt(IXmlReader* pReader, int& out);

public:
	SpriteFont() = delete;
	SpriteFont(std::string path);
	~SpriteFont();
	SpriteFont(const SpriteFont&) = delete;
	SpriteFont& operator=(const SpriteFont&) = delete;

	Glyph* GetGlyph(char c);
	float GetWidth();
	float GetHeight();
};

#endif _SpriteFont