// Ezequiel Arrieta
// GAM 374

#ifndef _TextureManager
#define _TextureManager

#include "AzulCore.h"
#include <map>


class TextureManager
{
private:
	friend class TextureManagerAttorney;
	static TextureManager* InstancePtr;

	//Big 4
	TextureManager();
	TextureManager(const TextureManager&) = delete;
	TextureManager& operator=(const TextureManager&) = delete;
	~TextureManager() = default;


	static TextureManager& Instance()			
	{
		if (!InstancePtr)
			InstancePtr = new TextureManager;
		return *InstancePtr;
	};
	using TextureMap = std::map<std::string, Texture*>;
	TextureMap StorageMap;

	void privateDelete();
	Texture* privateGet(std::string key);
	void privateLoad(std::string key, const std::string path, bool bDefault);
	void privateLoad(std::string key, unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha);

	std::string DefaultPath;
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Deletes this object. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void Delete() { Instance().privateDelete(); };
public:

	

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \ingroup TEXTUREMANAGER
	/// <summary>	Gets a texture* using the given key. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	///
	/// <param name="Key">	The key to get. </param>
	///
	/// <returns>	Null if it fails, else a pointer to a Texture. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static Texture* Get(const std::string Key) { return Instance().privateGet(Key); };


	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \ingroup TEXTUREMANAGER
	/// <summary>	Loads. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	///
	/// <param name="key">  	The key. </param>
	/// <param name="red">  	The red. </param>
	/// <param name="green">	The green. </param>
	/// <param name="blue"> 	The blue. </param>
	/// <param name="alpha">	(Optional) The alpha. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void Load(std::string key, unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha = 255) { Instance().privateLoad(key, red, green, blue, alpha); };

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \ingroup TEXTUREMANAGER
	/// <summary>	Loads. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/9/2021. </remarks>
	///
	/// <param name="key">	   	The key. </param>
	/// <param name="path">	   	Full pathname of the file. </param>
	/// <param name="bDefault">	(Optional) True to default. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void Load(const std::string key, const std::string path, bool bDefault = true) { Instance().privateLoad(key, path, bDefault); };
};

#endif _TextureManager
