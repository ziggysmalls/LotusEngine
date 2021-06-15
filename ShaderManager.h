// Ezequiel Arrieta
// GAM 374

#ifndef _ShaderManager
#define _ShaderManager

#include "AzulCore.h"
#include <map>

class ShaderManager
{
public:
	

private:
	friend class ShaderManagerAttorney;
	static ShaderManager* InstancePtr;

	//Big 4
	ShaderManager();
	ShaderManager(const ShaderManager&) = delete;
	ShaderManager& operator=(const ShaderManager&) = delete;
	~ShaderManager() = default;


	static ShaderManager& Instance()					
	{
		if (!InstancePtr)
			InstancePtr = new ShaderManager;
		return *InstancePtr;
	};
	using  ShaderMap = std::map<const std::string, ShaderObject*>;
	ShaderMap StorageMap;

	// Shader Methods
	void privateDelete();
	ShaderObject* privateGet(const std::string Key);
	void privateLoad(const std::string key, const std::string path);

	// Default Shader Methods
	void privateLoadDefaultShaders();
	
	void privateLoad(const std::string ds);


	std::string DefaultPath;
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Deletes this object. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void Delete() { Instance().privateDelete(); };

public:

	const std::string colorVaryRender = "Shaders/colorVaryRender";
	const std::string colorNoTextureLightRender = "Shaders/colorNoTextureLightRender";
	const std::string spriteRender = "Shaders/spriteRender";
	const std::string spriteLineRender = "Shaders/spriteLineRender";
	const std::string colorConstantRender = "Shaders/colorConstantRender";
	const std::string colorNoTextureRender = "Shaders/colorNoTextureRender";
	const std::string textureFlatRender = "Shaders/textureFlatRender";
	const std::string textureLightRender = "Shaders/textureLightRender";

	

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \ingroup SHADERMANAGER
	/// <summary>	Gets a shader object* using the given key. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	///
	/// <param name="Key">	The key to get. </param>
	///
	/// <returns>	Null if it fails, else a pointer to a ShaderObject. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static ShaderObject* Get(std::string Key) { return Instance().privateGet(Key); };

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \ingroup SHADERMANAGER
	/// <summary>	Loads. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	///
	/// <param name="key"> 	The key. </param>
	/// <param name="path">	Full pathname of the file. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void Load(std::string key, const std::string path) { Instance().privateLoad(key, path); };

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \ingroup SHADERMANAGER
	/// <summary>	Loads default shaders. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void LoadDefaultShaders() { Instance().privateLoadDefaultShaders(); };

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \ingroup SHADERMANAGER
	/// <summary>	Loads the given ds. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	///
	/// <param name="ds">	The ds to load. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void Load(const std::string ds) { Instance().privateLoad(ds); };
};

#endif _ShaderManager