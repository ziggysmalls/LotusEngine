#ifndef _CollisionDeregistrationCommand
#define _CollisionDeregistrationCommand

#include "SceneRegistrationCommand.h"
#include "Collidable.h"

class CollisionDeregistrationCommand : public SceneRegistrationCommand
{
private:
	Collidable* ptrCol;

public:
	CollisionDeregistrationCommand() = default;
	~CollisionDeregistrationCommand() = default;
	CollisionDeregistrationCommand(const CollisionDeregistrationCommand&) = delete;
	CollisionDeregistrationCommand& operator = (const CollisionDeregistrationCommand&) = delete;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Constructor. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	///
	/// <param name="cl">	[in,out] If non-null, the cl. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	CollisionDeregistrationCommand(Collidable* cl);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Executes this object. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void Execute() override;

};

#endif _CollisionDeregistrationCommand