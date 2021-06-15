// Ezequiel Arrieta
// GAM 374 
// Lotus
#include "LEMathTools.h"
#include "Vect.h"
#include "CollisionVolumeBSphere.h"
#include "CollisionVolumeAABB.h"
#include "CollisionVolumeOBB.h"
#include "Visualizer.h"

bool LEMathTools::Intersect(const CollisionVolume& A, const CollisionVolume& B)
{
	return A.IntersectAccept(B);
}

bool LEMathTools::Intersect(const CollisionVolumeBSphere& A, const CollisionVolumeBSphere& B)
{
	Vect sub(A.GetCenter() - B.GetCenter());

	return sub.mag() < (A.GetRadius() + B.GetRadius());
}

bool LEMathTools::Intersect(const CollisionVolumeAABB& A, const CollisionVolumeAABB& B)
{
	// Calculate Intervals
	Vect BA = B.GetMinAABB() - A.GetMaxAABB();
	Vect AB = A.GetMinAABB() - B.GetMaxAABB();

	if (BA.X() > 0.0f || BA.Y() > 0.0f || BA.Z() > 0.0f)
		return false;

	if (AB.X() > 0.0f || AB.Y() > 0.0f || AB.Z() > 0.0f)
		return false;

	return true;
}

bool LEMathTools::Intersect(const CollisionVolumeBSphere& A, const CollisionVolumeAABB& B)
{
	// Clamp BSphere Point between AABB's min and Max
	Vect cPoint = ClampPoint(A.GetCenter(), B.GetMinAABB(), B.GetMaxAABB());

	// Draw Clampig Point
	Visualizer::ShowBox(cPoint, Color::Green);

	// Test Clamp's point distance  < BSphere's radius
	return Range(cPoint, A.GetCenter(), A.GetRadius());
}
bool LEMathTools::Intersect(const CollisionVolumeOBB& A, const CollisionVolumeBSphere& B)
{
	// Clamp BSphere Point between OBB's min and Max
	Vect primeC = B.GetCenter() * A.GetWorld().getInv();

	//Vect cPoint = ClampPoint(B.GetCenter(), A.GetMinOBB(), A.GetMaxOBB());
	Vect cPoint = ClampPoint(primeC, A.GetMinOBB(), A.GetMaxOBB());

	cPoint = cPoint * A.GetWorld();
	// Draw Clampig Point
	Visualizer::ShowBox(cPoint, Color::Cyan);


	// Test Clamp's point distance  < BSphere's radius
	return Range(cPoint, B.GetCenter(), B.GetRadius());
}

bool LEMathTools::Intersect(const CollisionVolumeOBB& A, const CollisionVolumeOBB& B)
{
	Vect axis[15];

	Vect AXaxis = A.GetWorld().get(ROW_0);
	Vect AYaxis = A.GetWorld().get(ROW_1);
	Vect AZaxis = A.GetWorld().get(ROW_2);
	Vect BXaxis = B.GetWorld().get(ROW_0);
	Vect BYaxis = B.GetWorld().get(ROW_1);
	Vect BZaxis = B.GetWorld().get(ROW_2);

	axis[0] = AXaxis.cross(BXaxis);
	axis[1] = AXaxis.cross(BYaxis);
	axis[2] = AXaxis.cross(BZaxis);
	axis[3] = AYaxis.cross(BXaxis);
	axis[4] = AYaxis.cross(BYaxis);
	axis[5] = AYaxis.cross(BZaxis);
	axis[6] = AZaxis.cross(BXaxis);
	axis[7] = AZaxis.cross(BYaxis);
	axis[8] = AZaxis.cross(BZaxis);

	axis[9] = AXaxis;
	axis[10] = AYaxis;
	axis[11] = AZaxis;
	axis[12] = BXaxis;
	axis[13] = BYaxis;
	axis[14] = BZaxis;


	for (int i = 0; i < totalAxis; ++i)
	{
		// Validate perpendicular axes
		if (axis[i].magSqr() > FLT_EPSILON)
		{
			// Project A' d max on axis
			Vect vPrimeA = axis[i] * A.GetWorld().getInv();

			Vect MaxA = PlusMinusSignature(vPrimeA, A.GetDiagonal());

			float halfA = A.GetScaleSqred() * ProjectionMaxLength(axis[i], vPrimeA, MaxA);

			// Project B' d max on axis
			Vect vPrimeB = axis[i] * B.GetWorld().getInv();

			Vect MaxB = PlusMinusSignature(vPrimeB, B.GetDiagonal());

			float halfB = B.GetScaleSqred() * ProjectionMaxLength(axis[i], vPrimeB, MaxB);

			// Compare Projections against the Center's length projection
			Vect centerLength = B.GetCenter() - A.GetCenter();

			float d = ProjectionMaxLength(axis[i], centerLength, axis[i]);

			if (d > (halfA + halfB))
				return false;
		}
	}
	return true;
}
bool LEMathTools::Intersect(const CollisionVolumeOBB& A, const CollisionVolumeAABB& B)
{
	Vect axis[15];

	Vect AXaxis = A.GetWorld().get(ROW_0);
	Vect AYaxis = A.GetWorld().get(ROW_1);
	Vect AZaxis = A.GetWorld().get(ROW_2);
	Vect BXaxis = B.GetWorld().get(ROW_0);
	Vect BYaxis = B.GetWorld().get(ROW_1);
	Vect BZaxis = B.GetWorld().get(ROW_2);

	axis[0] = AXaxis.cross(BXaxis);
	axis[1] = AXaxis.cross(BYaxis);
	axis[2] = AXaxis.cross(BZaxis);
	axis[3] = AYaxis.cross(BXaxis);
	axis[4] = AYaxis.cross(BYaxis);
	axis[5] = AYaxis.cross(BZaxis);
	axis[6] = AZaxis.cross(BXaxis);
	axis[7] = AZaxis.cross(BYaxis);
	axis[8] = AZaxis.cross(BZaxis);

	axis[9] = AXaxis;
	axis[10] = AYaxis;
	axis[11] = AZaxis;
	axis[12] = BXaxis;
	axis[13] = BYaxis;
	axis[14] = BZaxis;

	for (int i = 0; i < totalAxis; ++i)
	{
		// Validate perpendicular axes
		if (axis[i].magSqr() > FLT_EPSILON)
		{
			// Project A' d max on axis
			Vect vPrimeA = axis[i] * A.GetWorld().getInv();

			Vect MaxA = PlusMinusSignature(vPrimeA, A.GetDiagonal());

			float halfA = A.GetScaleSqred() * ProjectionMaxLength(axis[i], vPrimeA, MaxA);

			// Project B' d max on axis
			Vect vPrimeB = axis[i] * B.GetWorld().getInv();

			Vect MaxB = PlusMinusSignature(vPrimeB, B.GetDiagonal());

			float halfB = B.GetScaleSqred() * ProjectionMaxLength(axis[i], vPrimeB, MaxB);

			// Compare Projections against the Center's length projection
			Vect centerLength = B.GetCenter() - A.GetCenter();

			float d = ProjectionMaxLength(axis[i], centerLength, axis[i]);

			if (d > (halfA + halfB))
				return false;
		}
	}
	return true;
}

bool LEMathTools::Intersect(const CollisionVolumeBSphere& A, const Vect& AABBmin, const Vect& AABBmax)
{
	// Clamp BSphere Point between AABB's min and Max
	Vect cPoint = ClampPoint(A.GetCenter(), AABBmin, AABBmax);


	// Test Clamp's point distance  < BSphere's radius
	return Range(cPoint, A.GetCenter(), A.GetRadius());
}

bool LEMathTools::Intersect(const Vect& CenBS, const float& BSrad, const Vect& AABBmin, const Vect& AABBmax)
{
	// Clamp BSphere Point between AABB's min and Max
	Vect cPoint = ClampPoint(CenBS, AABBmin, AABBmax);

	// Test Clamp's point distance  < BSphere's radius
	return Range(cPoint, CenBS, BSrad);
}

Vect LEMathTools::PlusMinusSignature(const Vect& v, const Vect& d)
{
	float mx, my, mz;

	if (v.X() < 0)
		mx = -1 * abs(d.X());
	else
		mx = abs(d.X());

	if (v.Y() < 0)
		my = -1 * abs(d.Y());
	else
		my = abs(d.Y());

	if (v.Z() < 0)
		mz = -1 * abs(d.Z());
	else
		mz = abs(d.Z());

	return Vect(mx, my, mz);
}

float LEMathTools::ProjectionMaxLength(const Vect& v, const Vect& vPrime, const Vect& w)
{
	return (abs(vPrime.dot(w)) / EuclideanNorm(v));
}

float LEMathTools::EuclideanNorm(const Vect& v)
{
	return sqrtf(v.dot(v));
}


Vect LEMathTools::ClampPoint(const Vect& point, const Vect& min, const Vect& max)
{
	return Vect(
		Max(min.X(), Min(point.X(), max.X())),
		Max(min.Y(), Min(point.Y(), max.Y())),
		Max(min.Z(), Min(point.Z(), max.Z())));
}
Vect LEMathTools::MinimumVect(const Vect& a, const Vect& b)
{
	return Vect(Min(a.X(), b.X()), Min(a.Y(), b.Y()), Min(a.Z(), b.Z()));
}


Vect LEMathTools::MaximumVect(const Vect& a, const Vect& b)
{
	return Vect(Max(a.X(), b.X()), Max(a.Y(), b.Y()), Max(a.Z(), b.Z()));
}
float LEMathTools::DistanceTwoPoints(const Vect& v1, const Vect& v2)
{
	return (v1 - v2).mag();
}
bool LEMathTools::Range(const Vect& v1, const Vect& v2, const float dis)
{
	return (v1 - v2).mag() < dis;
}

float LEMathTools::Min(const float a, const float b)
{
	if (a > b) return b;
	if (b > a) return a;
	return a;
}

float LEMathTools::Max(const float a, const float b)
{
	if (a < b) return b;
	if (b < a) return a;
	return a;
}

float LEMathTools::GetAngleDegrees(const Vect& v1, const Vect& v2)
{
	return RadiansToDegrees(v1.dot(v2) / (v1.mag() * v2.mag()));
}

float LEMathTools::RadiansToDegrees(const float rad)
{
	return rad * 180.f / 3.141592f;
}
Vect LEMathTools::Interpolate(const Vect& P, const Vect& Qa, const Vect& Qb, const Vect& Qc)
{
	Vect V0, V1, V2, Quantity;
	V0 = Qb - Qa;
	V1 = Qc - Qb;
	V2 = P - Qa;

	float A, B, C, D, E;
	A = V0.dot(V0);
	B = V1.dot(V0);
	C = V1.dot( V1);
	D = V2.dot(V0);
	E = V2.dot(V1);

	float Beta, Gamma;
	Beta = ((D * C) - (B * E)) / ((A * C) - (B * B));
	Gamma = ((A * E) - (D * B)) / ((A * C) - (B * B));

	Quantity = Qa + Beta * (Qb - Qa) + Gamma * (Qc - Qb);

	return Quantity;
}

