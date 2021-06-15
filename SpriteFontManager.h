#ifndef _SpriteFontManager
#define _SpriteFontManager

#include <map>

class SpriteFont;
class SpriteFontManager
{
	friend class SpriteFontManagerAttorney;

	static SpriteFontManager* InstancePtr;

	SpriteFontManager();
	SpriteFontManager(const SpriteFontManager&) = delete;
	SpriteFontManager& operator=(const SpriteFontManager&) = delete;
	~SpriteFontManager() = default;

	static SpriteFontManager& Instance()					// Access reference (all public methods will be static)
	{
		if (!InstancePtr)
			InstancePtr = new SpriteFontManager;
		return *InstancePtr;
	};

	void privDelete();
	SpriteFont* privGet(std::string key);
	void privLoad(const std::string key, const std::string path);

	std::string DefaultPath;

	using  FontCol = std::map<std::string, SpriteFont*>;
	FontCol storageMap;

	static void Delete() { Instance().privDelete(); };
	
public:

	

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \ingroup FONTMANAGER
	/// <summary>	Gets a sprite font* using the given key. </summary>
	///
	/// <remarks>	Ezequ, 3/14/2021. </remarks>
	///
	/// <param name="Key">	The key to get. </param>
	///
	/// <returns>	Null if it fails, else a pointer to a SpriteFont. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static SpriteFont* Get(const std::string Key) { return Instance().privGet(Key); };

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \ingroup FONTMANAGER
	/// <summary>	Loads. </summary>
	///
	/// <remarks>	Ezequ, 3/14/2021. </remarks>
	///
	/// <param name="key"> 	The key. </param>
	/// <param name="path">	Full pathname of the file. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void Load(const std::string key, const std::string path) { Instance().privLoad(key, path); };

};

#endif _SpriteFontManager