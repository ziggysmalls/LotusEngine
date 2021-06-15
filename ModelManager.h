// Ezequiel Arrieta
// GAM 374

#ifndef _ModelManager
#define _ModelManager

#include "AzulCore.h"
#include <map>
class Model;
class ModelManager
{
private:
	friend class ModelManagerAttorney;
	static ModelManager* InstancePtr;

	// Big 4
	ModelManager();
	ModelManager(const ModelManager&) = delete;
	ModelManager& operator = (const ModelManager&) = delete;
	~ModelManager() = default;

	static ModelManager& Instance()
	{
		if (!InstancePtr)
			InstancePtr = new ModelManager;
		return *InstancePtr;
	}

	using ModelMap = std::map<std::string, Model*>;
	ModelMap StorageMap;
	std::string DefaultPath;

	void privateDelete();
	Model* privateGet(const std::string Key);


	void privateLoad(std::string key, const std::string path);
	void privateLoad(std::string key, Model::PreMadeModels pm);
	void privateLoadDefaultModels();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Deletes the singleton. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void Delete() { Instance().privateDelete(); };
public:
	const std::string Sprite = "Sprite";

	

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \ingroup MODELMANAGER
	/// <summary>	Gets a model* using the given key. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	///
	/// <param name="Key">	The key to get. </param>
	///
	/// <returns>	Null if it fails, else a pointer to a Model. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static Model* Get(const std::string Key) { return Instance().privateGet(Key); };

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \ingroup MODELMANAGER
	/// <summary>	Loads. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	///
	/// <param name="key"> 	The key. </param>
	/// <param name="path">	Full pathname of the file. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void Load(std::string key, const std::string path) { Instance().privateLoad(key, path); };

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \ingroup MODELAMANAGER
	/// <summary>	Loads. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	///
	/// <param name="key">	The key. </param>
	/// <param name="pm"> 	The pm. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void Load(std::string key, Model::PreMadeModels pm) { Instance().privateLoad(key, pm); };

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \ingroup MODELMANAGER
	/// <summary>	Loads default models. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void LoadDefaultModels() { Instance().privateLoadDefaultModels(); };




};
#endif _ModelManager



