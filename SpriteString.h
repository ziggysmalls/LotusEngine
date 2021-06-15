#ifndef _SpriteString
#define _SpriteString
#include <vector>
#include "SpriteFont.h"
#include "LotusSprite.h"

class SpriteString
{
	int posx;
	int posy;
	int height;
	int width;
	SpriteFont* sfont;

	using GlypCollection = std::vector<LotusSprite*>;
	GlypCollection glyphs;

	SpriteString(const SpriteString&) = delete;
	SpriteString& operator=(const SpriteString&) = delete;

public:
	~SpriteString() = default;
	SpriteString();
	SpriteString(const SpriteFont&);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Constructor. </summary>
	///
	/// <remarks>	Ezequ, 3/10/2021. </remarks>
	///
	/// <param name="sf">	[in,out] If non-null, the sf. </param>
	/// <param name="s"> 	A std::string to process. </param>
	/// <param name="x"> 	The x coordinate. </param>
	/// <param name="y"> 	The y coordinate. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	SpriteString(SpriteFont* sf, std::string s, int x, int y);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the height. </summary>
	///
	/// <remarks>	Ezequ, 3/10/2021. </remarks>
	///
	/// <returns>	The height. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	int GetHeight();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the width. </summary>
	///
	/// <remarks>	Ezequ, 3/10/2021. </remarks>
	///
	/// <returns>	The width. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	int GetWidth();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Renders this object. </summary>
	///
	/// <remarks>	Ezequ, 3/10/2021. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void Render();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets. </summary>
	///
	/// <remarks>	Ezequ, 3/10/2021. </remarks>
	///
	/// <param name="x">	The x coordinate. </param>
	/// <param name="y">	The y coordinate. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void Set(int x, int y);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets. </summary>
	///
	/// <remarks>	Ezequ, 3/10/2021. </remarks>
	///
	/// <param name="sf">	[in,out] If non-null, the sf. </param>
	/// <param name="s"> 	A std::string to process. </param>
	/// <param name="x"> 	The x coordinate. </param>
	/// <param name="y"> 	The y coordinate. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void Set(SpriteFont* sf, std::string s, int x, int y);
};

#endif _SpriteString