#ifndef _Visualizer
#define _Visualizer

#include "Vect.h"
#include "GraphicsObject_WireframeConstantColor.h"
#include <list>
#include "CollisionVolumeBSphere.h"
#include "CollisionVolumeAABB.h"
#include "CollisionVolumeOBB.h"
#include "VisualizerCommand.h"
#include "AABBVisualizerCommand.h"
#include "Color.h"

class VisualizerCommandBase;
class CollisionVolume;
class Visualizer
{
	friend class VisualizerAttorney;
private:
	static Visualizer* InstancePtr;

	Visualizer();
	Visualizer(const Visualizer&) = delete;
	Visualizer& operator=(const Visualizer&) = delete;
	~Visualizer() = default;


	static Visualizer& Instance()
	{
		if (!InstancePtr)
			InstancePtr = new Visualizer;
		return *InstancePtr;
	}

	// List
	using VisualCmdCol = std::list<VisualizerCommandBase*>;
	VisualCmdCol VisualizerListCol;

	void privateDelete();
	void privateVisualizeAll();

	void privShowSphere(const CollisionVolumeBSphere& S, const Vect& V);
	void privShowCVolume(const CollisionVolume& cv, const Vect& c, bool bCol);
	void privShowAABB(const CollisionVolumeAABB& ab, const Vect& c);
	void privShowAABB(const Vect& min, const Vect& max, const Vect& c);
	void privShowOBB(const CollisionVolumeOBB& ab, const Vect& c);
	void privBox(const Vect& center, const Vect& col, float scale = 1.0f);
	void privShowVerticalLine(const Vect& orig, const float len, const Vect& col = DEFAULT_COLOR);

	void privRenderBSphere(Matrix& S, const Vect& col);
	void privRenderBox(Matrix& S, const Vect& col);


	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static void Visualizer::VisualizeAll()
	///
	/// \brief	Visualize all the BSpheres registered
	/// 		Draws the BSpheres of all the collidible objects that were registered to be visualized.
	/// 		Is an internal method which means is not user accessible.
	/// 
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void VisualizeAll() { Instance().privateVisualizeAll(); };

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static void Visualizer::Delete()
	///
	/// \brief	Deletes the Singleton Instance 
	///
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void Delete() { return Instance().privateDelete(); };

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static void Visualizer::RenderBSphere(Matrix& S, const Vect& col)
	///
	/// \brief	Renders the BSphere
	/// 		Callback method that renders a BSpheres given a Matrix and a color.
	///
	/// \param [in,out]	S  	A Matrix to process.
	/// \param 		   	col	The color.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void RenderBSphere(Matrix& S, const Vect& col) { Instance().privRenderBSphere(S, col); };



	static void RenderBox(Matrix& S, const Vect& col) { Instance().privRenderBox(S, col); };


	// Data
	static Vect DEFAULT_COLOR;
	static Vect DEFAULT_COLOR2;
	bool bToggle;
	GraphicsObject_WireframeConstantColor* WFUnitSphere;
	GraphicsObject_WireframeConstantColor* WFBox;

	// Clamp Point Rendering
	void privToggle();

public:
	

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static void Visualizer::Toggle()
	///
	/// \brief	Toggles on or off the visualizer by pressing F8
	/// 		
	/// \ingroup VISUALIZER
	/// 
	/// 
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static void Toggle() { Instance().privToggle(); };

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static void Visualizer::ShowSphere(const CollisionVolumeBSphere& S, const Vect& col = DEFAULT_COLOR)
	///
	/// \brief	Visualizes a Collidable's BSphere
	/// 		
	/// \ingroup VISUALIZER
	/// Example:
	/// \code
	/// void Player::Collision(Bullet*)
	///		{
	///			// Draws a red wired BSphere around the player's model while colliding with a bullet
	///			Visualizer::ShowSphere(this->GetSphere(), Color::Red);
	///		}
	/// 
	/// void Player::Collision(Enemy*)
	///		{
	///			// Draws a yellow wired BSphere around the player's model while colliding with an enemy
	///			Visualizer::ShowSphere(this->GetSphere(), Color::Yellow);
	///		}
	///		
	/// \endcode
	/// \param 	S  	A CollisionVolumeBSphere to process.
	/// \param 	col	(Optional) The color of the BSphere.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void ShowSphere(const CollisionVolumeBSphere& S, const Vect& col = DEFAULT_COLOR) { Instance().privShowSphere(S, col); };


	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static void Visualizer::ShowAABB(const CollisionVolumeAABB& S, const Vect& col = DEFAULT_COLOR)
	///
	/// \brief	Visualizes a Collidable's AABB
	/// 		
	/// \ingroup VISUALIZER
	/// Example:
	/// \code
	/// void Player::Collision(Bullet*)
	///		{
	///			// Draws a red wired AABB box around the player's model while colliding with a bullet
	///			Visualizer::ShowAABB(this->GetAABB(), Color::Red);
	///		}
	/// 
	/// void Player::Collision(Enemy*)
	///		{
	///			// Draws a yellow wired AABB box around the player's model while colliding with an enemy
	///			Visualizer::ShowAABB(this->GetAABB(), Color::Yellow);
	///		}
	///		
	/// \endcode
	/// \param 	S  	A CollisionVolumeAABB to process.
	/// \param 	col	(Optional) The color of the AABB.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static void ShowAABB(const CollisionVolumeAABB& S, const Vect& col = DEFAULT_COLOR) { Instance().privShowAABB(S, col); };

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static void Visualizer::ShowAABB(const Vect& min, const Vect& max, const Vect& col = DEFAULT_COLOR)
	///
	/// \brief	Visualizes a Collidable's AABB
	/// 		
	/// This functions renders an AABB given only a min and max values instead of the actual collision volume
	/// \ingroup VISUALIZER
	/// Example:
	/// \code
	/// void Player::Collision(Bullet*)
	///		{
	///			// Draws a red wired AABB box around the player's model while colliding with a bullet
	///			Visualizer::ShowAABB(this->minAABB, this->maxAABB, Color::Red);
	///		}
	/// 
	/// void Player::Collision(Enemy*)
	///		{
	///			// Draws a yellow wired AABB box around the player's model while colliding with an enemy
	///			Visualizer::ShowAABB(this->minAABB, this->maxAABB, Color::Yellow);
	///		}
	///		
	/// \endcode
	/// \param 	min The raw Vect value for an AABB's min
	/// \param 	max The raw Vect value for an AABB's max
	/// \param 	col	(Optional) The color of the AABB.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static void ShowAABB(const Vect& min, const Vect& max, const Vect& col = DEFAULT_COLOR) { Instance().privShowAABB(min, max, col); };


	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static void Visualizer::ShowOBB(const CollisionVolumeOBB& o, const Vect& col = DEFAULT_COLOR)
	///
	/// \brief	Visualizes a Collidable's OBB
	/// 		
	/// This functions renders an OBB given only a min and max values instead of the actual collision volume
	/// \ingroup VISUALIZER
	/// Example:
	/// \code
	/// Player::Player()
	/// {
	///		// We need to set up the collision volume of this GO to be an OBB
	///		SetColliderModel(this->Model, OBB);
	/// }
	/// 
	/// void Player::Collision(Bullet*)
	///		{
	///			// Draws a black wired OBB box around the player's model while colliding with a bullet
	///			Visualizer::ShowAABB(this->GetCollisionVolume(), this->maxAABB, Color::Black);
	///		}
	/// 
	/// void Player::Collision(Enemy*)
	///		{
	///			// Draws a white wired OBB box around the player's model while colliding with an enemy
	///			Visualizer::ShowAABB(this->GetCollisionVolume(), this->maxAABB, Color::White);
	///		}
	///		
	/// \endcode
	/// \param 	o The OBB collision volume attach to a game object
	/// \param 	col	(Optional) The color of the AABB.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static void ShowOBB(const CollisionVolumeOBB& o, const Vect& col = DEFAULT_COLOR) { Instance().privShowOBB(o, col); };


	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static void Visualizer::ShowBox(const Vect& center, const Vect& col = DEFAULT_COLOR, float scale = 1.0f)
	///
	/// \brief	Renders a Wire Frame Box given a center, color and scale
	/// 		
	/// \ingroup VISUALIZER
	/// It will a render a box given a point in world space
	/// Example:
	/// \code
	/// void Player::Update()
	///		{
	///			// Draws an Orange wired box of 1 unit around the player's center in world space
	///			Visualizer::ShowBox(Player.GetCenter(), Color::Orange);
	///		}
	/// 
	/// void Player::Update()
	///		{
	///			// Draws a NavyBlue wired box around the player's center in world space with an scale of 10
	///			Visualizer::ShowBox( Player.getCenter(), Color::NavyBlue, 10.0f);
	///		}
	///		
	/// \endcode
	/// \param 	center 	The Box's Center.
	/// \param 	col	(Optional) The color of the Box.
	/// \param 	scale(Optional) The scale of the Box.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static void ShowBox(const Vect& center, const Vect& col = DEFAULT_COLOR, float scale = 1.0f) { Instance().privBox(center, col, scale); };


	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static void Visualizer::ShowCollisionVolume(const CollisionVolume& ab, const Vect& col = DEFAULT_COLOR, bool isColliding = false)
	///
	/// \brief	Renders a GO's Collision Volume
	/// 		
	/// \ingroup VISUALIZER
	/// NOTE: This method is usually for internal engine use, but can be used to force collision debugging.
	///	IMPORTANT: the param isColliding makes little sense to the user since it was design to be used solely by the engine.
	/// It will a render whaterver Collision Volume is attached to a particular Game Object.  
	/// If a GO has a Bsphere, it will draw a wired frame sphere, if its an AABB it will render a wired frame Box
	/// 
	/// Example:
	/// \code
	/// void Player::Update()
	///		{
	///			// Draws an Orange wired box around the player's min and Max values in world space
	///			Visualizer::ShowCollisionVolume(Player.GetABBB(), Color::Pink);
	///		}
	/// 
	/// void Player::Collision(Enemy*)
	///		{
	///			// Draws a NavyBlue wired box around the player's center in world space with an scale of 10
	///			Visualizer::ShowCollisionVolume(Player.GetABBB(), Color::NavyBlue);
	///		}
	///		
	/// \endcode
	/// \param 	ab 	The Collision Volume.
	/// \param 	col	(Optional) The color of the Collision Volume.
	/// \param 	isColliding (Optional) bool variable to change the color's Volume if it's Colliding.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static void ShowCollisionVolume(const CollisionVolume& ab, const Vect& col = DEFAULT_COLOR, bool isColliding = false) { Instance().privShowCVolume(ab, col, isColliding); };

	//static void ShowLine(const Vect& cen, const Vect& dir,  const float len,  const Vect& col = DEFAULT_COLOR) {  Instance().privShowLine(cen, dir, len, col); };



	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static void Visualizer::ShowVerticalLine(const Vect& orig, const float dir, const Vect& col = DEFAULT_COLOR)
	///
	/// \brief	Renders a vertical line given a position in world space 
	/// 		
	/// \ingroup VISUALIZER
	/// This function will render a vertical line given a point in world space, that will be the center. 
	/// We can then choose its direction in length.
	/// 
	/// Example:
	/// \code
	/// void Player::Update()
	///		{
	///			// Draws an Orange wired box around the player's min and Max values in world space
	///			Visualizer::ShowVerticalLine(this->PlayerPosition, Color::Pink);
	///		}
	///
	///		
	/// \endcode
	/// \param 	orig 	The Collision Volume.
	/// \param 	dir		This is the direction and lenght of the line, negative goes downwards, positive upwards
	/// \param	col		(Optional) The color of the Collision Volume.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static void ShowVerticalLine(const Vect& orig, const float dir, const Vect& col = DEFAULT_COLOR) { Instance().privShowVerticalLine(orig, dir, col); };



};
#endif _Visualizer