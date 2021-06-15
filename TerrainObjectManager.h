#ifndef _TerrainObjectManager
#define _TerrainObjectManager

#include "AzulCore.h"
#include <map>

class TerrainObject;
class TerrainObjectManager
{
private:
	friend class TerrainObjManagerAttorney;

	static TerrainObjectManager* InstancePtr;

	//Big 4
	TerrainObjectManager();
	TerrainObjectManager(const TerrainObjectManager&) = delete;
	TerrainObjectManager& operator=(const TerrainObjectManager&) = delete;
	~TerrainObjectManager() = default;


	static TerrainObjectManager& Instance()					// Access reference (all public methods will be static)
	{
		if (!InstancePtr)
			InstancePtr = new TerrainObjectManager;
		return *InstancePtr;
	};

	using TerrainMap = std::map<std::string, TerrainObject*>;
	TerrainMap storageMap;

	// Private non static methods  for user use
	void privDelete();
	TerrainObject* privGet(std::string key);
	void privSetTerrain(const char* key);
	void privDeregisterTerrain();
	void privLoad(std::string key, const char* fileName, int len, float maxheight, float altY, float Xoffset, float Yoffset, std::string tex, int RepeatU, int RepeatV);
	TerrainObject* privGetCurrTerrain();

	// Private static method for engine use
	static void Delete() { Instance().privDelete(); };

	// Data
	std::string DefaultPath;
	TerrainObject* pcurrTerrain;
public:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets a terrain object* using the given key. </summary>
	///
	/// <remarks>	Ezequ, 5/19/2021. </remarks>
	///
	/// <param name="Key">	The key to get. </param>
	///
	/// <returns>	Null if it fails, else a pointer to a TerrainObject. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static TerrainObject* Get(const std::string Key) { return Instance().privGet(Key); };

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Loads. </summary>
	///
	/// <remarks>	Ezequ, 5/19/2021. </remarks>
	///
	/// <param name="key">			The key. </param>
	/// <param name="fileName"> 	Filename of the file. </param>
	/// <param name="len">			The length. </param>
	/// <param name="maxheight">	The maxheight. </param>
	/// <param name="altY">			The alternate y coordinate. </param>
	/// <param name="Xoffset">  	The xoffset. </param>
	/// <param name="Zoffset">  	The zoffset. </param>
	/// <param name="tex">			The tex. </param>
	/// <param name="RepeatU">  	The repeat u. </param>
	/// <param name="RepeatV">  	The repeat v. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void Load(std::string key, const char* fileName, int len, float maxheight, float altY, float Xoffset, float Zoffset, std::string tex, int RepeatU, int RepeatV) { Instance().privLoad(key, fileName, len, maxheight, altY, Xoffset, Zoffset, tex, RepeatU, RepeatV); };

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets a terrain. </summary>
	///
	/// <remarks>	Ezequ, 5/19/2021. </remarks>
	///
	/// <param name="key">	The key. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void SetTerrain(const char* key) { Instance().privSetTerrain(key); };

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets current terrain. </summary>
	///
	/// <remarks>	Ezequ, 5/19/2021. </remarks>
	///
	/// <returns>	Null if it fails, else the current terrain. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static TerrainObject* GetCurrentTerrain() { return  Instance().privGetCurrTerrain(); };

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Deregisters the terrain. </summary>
	///
	/// <remarks>	Ezequ, 5/19/2021. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void DeregisterTerrain() { Instance().privDeregisterTerrain(); };

};

#endif _TerrainObjectManager