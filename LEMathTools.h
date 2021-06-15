#ifndef _LEMathTools
#define _LEMathTools
class CollisionVolumeBSphere;
class CollisionVolume;
class CollisionVolumeAABB;
class CollisionVolumeOBB;
class Vect;
class LEMathTools
{
private:
	static const int totalAxis = 15;
public:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \ingroup MATH
	/// <summary>	Intersects. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	///
	/// <param name="A">	A CollisionVolumeBSphere to process. </param>
	/// <param name="B">	A CollisionVolumeBSphere to process. </param>
	///
	/// <returns>	True if it succeeds, false if it fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static bool Intersect(const CollisionVolumeBSphere& A, const CollisionVolumeBSphere& B);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \ingroup MATH
	/// <summary>	Intersects. </summary>
	///
	/// <remarks>	Ezequ, 5/3/2021. </remarks>
	///
	/// <param name="A">	A CollisionVolumeBSphere to process. </param>
	/// <param name="B">	A CollisionVolumeAABB to process. </param>
	///
	/// <returns>	True if it succeeds, false if it fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static bool Intersect(const CollisionVolumeBSphere& A, const CollisionVolumeAABB& B);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \ingroup MATH
	/// <summary>	Intersects. </summary>
	///
	/// <remarks>	Ezequ, 5/3/2021. </remarks>
	///
	/// <param name="A">	A CollisionVolumeAABB to process. </param>
	/// <param name="B">	A CollisionVolumeAABB to process. </param>
	///
	/// <returns>	True if it succeeds, false if it fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static bool Intersect(const CollisionVolumeAABB& A, const CollisionVolumeAABB& B);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \ingroup MATH
	/// <summary>	Intersects. </summary>
	///
	/// <remarks>	Ezequ, 5/3/2021. </remarks>
	///
	/// <param name="A">	A CollisionVolumeOBB to process. </param>
	/// <param name="B">	A CollisionVolumeOBB to process. </param>
	///
	/// <returns>	True if it succeeds, false if it fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static bool Intersect(const CollisionVolumeOBB& A, const CollisionVolumeOBB& B);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \ingroup MATH
	/// <summary>	Intersects. </summary>
	///
	/// <remarks>	Ezequ, 5/3/2021. </remarks>
	///
	/// <param name="A">	A CollisionVolumeOBB to process. </param>
	/// <param name="B">	A CollisionVolumeAABB to process. </param>
	///
	/// <returns>	True if it succeeds, false if it fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static bool Intersect(const CollisionVolumeOBB& A, const CollisionVolumeAABB& B);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \ingroup MATH
	/// <summary>	Intersects. </summary>
	///
	/// <remarks>	Ezequ, 5/3/2021. </remarks>
	///
	/// <param name="A">	A CollisionVolumeOBB to process. </param>
	/// <param name="B">	A CollisionVolumeBSphere to process. </param>
	///
	/// <returns>	True if it succeeds, false if it fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static bool Intersect(const CollisionVolumeOBB& A, const CollisionVolumeBSphere& B);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \ingroup MATH
	/// <summary>	Intersects. </summary>
	///
	/// <remarks>	Ezequ, 5/3/2021. </remarks>
	///
	/// <param name="A">	A CollisionVolume to process. </param>
	/// <param name="B">	A CollisionVolume to process. </param>
	///
	/// <returns>	True if it succeeds, false if it fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static bool Intersect(const CollisionVolume& A, const CollisionVolume& B);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \ingroup MATH
	/// <summary>	Clamp point. </summary>
	///
	/// <remarks>	Ezequ, 5/3/2021. </remarks>
	///
	/// <param name="point">	The point. </param>
	/// <param name="min">  	The minimum. </param>
	/// <param name="max">  	The maximum. </param>
	///
	/// <returns>	A Vect. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static Vect ClampPoint(const Vect& point, const Vect& min, const Vect& max);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \ingroup MATH
	/// <summary>	Ranges. </summary>
	///
	/// <remarks>	Ezequ, 5/3/2021. </remarks>
	///
	/// <param name="v1"> 	The first value. </param>
	/// <param name="v2"> 	The second value. </param>
	/// <param name="dis">	The dis. </param>
	///
	/// <returns>	True if it succeeds, false if it fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static bool Range(const Vect& v1, const Vect& v2, const float dis);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \ingroup MATH
	/// <summary>	Determines the minimum of the given parameters. </summary>
	///
	/// <remarks>	Ezequ, 5/3/2021. </remarks>
	///
	/// <param name="a">	A float to process. </param>
	/// <param name="b">	A float to process. </param>
	///
	/// <returns>	The minimum value. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static float Min(const float a, const float b);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \ingroup MATH
	/// <summary>	Determines the maximum of the given parameters. </summary>
	///
	/// <remarks>	Ezequ, 5/3/2021. </remarks>
	///
	/// <param name="a">	A float to process. </param>
	/// <param name="b">	A float to process. </param>
	///
	/// <returns>	The maximum value. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static float Max(const float a, const float b);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \ingroup MATH
	/// <summary>	Plus minus signature. </summary>
	///
	/// <remarks>	Ezequ, 5/3/2021. </remarks>
	///
	/// <param name="v">	A Vect to process. </param>
	/// <param name="d">	A Vect to process. </param>
	///
	/// <returns>	A Vect. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static Vect PlusMinusSignature(const Vect& v, const Vect& d);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \ingroup MATH
	/// <summary>	Euclidean normalize. </summary>
	///
	/// <remarks>	Ezequ, 5/3/2021. </remarks>
	///
	/// <param name="v">	A Vect to process. </param>
	///
	/// <returns>	A float. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static float EuclideanNorm(const Vect& v);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \ingroup MATH
	/// <summary>	Projection maximum length. </summary>
	///
	/// <remarks>	Ezequ, 5/3/2021. </remarks>
	///
	/// <param name="v">	 	A Vect to process. </param>
	/// <param name="vPrime">	The prime. </param>
	/// <param name="w">	 	A Vect to process. </param>
	///
	/// <returns>	A float. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static float ProjectionMaxLength(const Vect& v, const Vect& vPrime, const Vect& w);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \ingroup MATH
	/// <summary>	Maximum vect. </summary>
	///
	/// <remarks>	Ezequ, 5/3/2021. </remarks>
	///
	/// <param name="a">	A Vect to process. </param>
	/// <param name="b">	A Vect to process. </param>
	///
	/// <returns>	A Vect. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static Vect MaximumVect(const Vect& a, const Vect& b);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \ingroup MATH
	/// <summary>	Minimum vect. </summary>
	///
	/// <remarks>	Ezequ, 5/3/2021. </remarks>
	///
	/// <param name="a">	A Vect to process. </param>
	/// <param name="b">	A Vect to process. </param>
	///
	/// <returns>	A Vect. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static Vect MinimumVect(const Vect& a, const Vect& b);
	static Vect Interpolate(const Vect& P, const Vect& A, const Vect& B, const Vect& C);
	static float GetAngleDegrees(const Vect& v1, const Vect& v2);
	static bool Intersect(const Vect& CenBS, const float& BSrad, const Vect& AABBmin, const Vect& AABBmax);
	static float RadiansToDegrees(const float rad);
	static bool Intersect(const CollisionVolumeBSphere& A, const Vect& AABBmin, const Vect& AABBmax);

	static float DistanceTwoPoints(const Vect& v1, const Vect& v2);

};
#endif _LEMathTools