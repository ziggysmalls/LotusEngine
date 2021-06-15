#ifndef _CameraManager
#define _CameraManager

#include "AzulCore.h"

class CameraManager
{
private:
	// private camera references
	Camera* currentCamera;
	Camera* defaultCamera;
	Camera* default2DCamera;
	Camera* current2DCamera;
	void Delete();


	

public:

	 ////////////////////////////////////////////////////////////////////////////////////////////////////
	 /// <summary>	Gets current camera. </summary>
	 ///
	 /// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	 ///
	 /// <returns>	Null if it fails, else the current camera. </returns>
	 ////////////////////////////////////////////////////////////////////////////////////////////////////

	 Camera* GetCurrentCamera(); 

	 ////////////////////////////////////////////////////////////////////////////////////////////////////
	 /// <summary>	Gets current 2D camera. </summary>
	 ///
	 /// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	 ///
	 /// <returns>	Null if it fails, else the current 2D camera. </returns>
	 ////////////////////////////////////////////////////////////////////////////////////////////////////

	 Camera* GetCurrent2DCamera();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets a new camera. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	///
	/// <param name="newcam">	[in,out] If non-null, the newcam. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void SetCurrentCamera(Camera* newcam);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets current 2D camera. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	///
	/// <param name="newcam">	[in,out] If non-null, the newcam. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void SetCurrent2DCamera(Camera* newcam);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Updates Current Camera. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void Update();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets a perspective. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	///
	/// <param name="FieldOfView_Degs">	The field of view in degrees. </param>
	/// <param name="AspectRatio">	   	The aspect ratio. </param>
	/// <param name="NearDist">		   	The near distance. </param>
	/// <param name="FarDist">		   	The far distance. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void setPerspective(const float FieldOfView_Degs, const float AspectRatio, const float NearDist, const float FarDist);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets an orthographic. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	///
	/// <param name="xMin">	The minimum. </param>
	/// <param name="xMax">	The maximum. </param>
	/// <param name="yMin">	The minimum. </param>
	/// <param name="yMax">	The maximum. </param>
	/// <param name="zMin">	The minimum. </param>
	/// <param name="zMax">	The maximum. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void setOrthographic(const float xMin, const float xMax, const float yMin, const float yMax, const float zMin, const float zMax);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets a viewport. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	///
	/// <param name="inX">   	The in x coordinate. </param>
	/// <param name="inY">   	The in y coordinate. </param>
	/// <param name="width"> 	The width. </param>
	/// <param name="height">	The height. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void setViewport(const int inX, const int inY, const int width, const int height);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets orient and position. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	///
	/// <param name="Up_vect">	  	The up vect. </param>
	/// <param name="inLookAt_pt">	The in look at point. </param>
	/// <param name="pos_pt">	  	The position point. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void setOrientAndPosition(const Vect& Up_vect, const Vect& inLookAt_pt, const Vect& pos_pt);

	CameraManager();
	CameraManager(const CameraManager&) = delete;
	CameraManager& operator=(const CameraManager&) = delete;
	~CameraManager();
	
	

};

#endif _CameraManager