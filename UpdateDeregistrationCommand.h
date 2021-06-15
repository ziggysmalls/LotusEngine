// Ezequiel Arrieta
// GAM 374
// Lotus

#ifndef _UpdateDeregistrationCommand
#define _UpdateDeregistrationCommand

#include "CommandBase.h"
#include "Updatable.h"

class UpdateDeregistrationCommand : public CommandBase
{
private:
	Updatable* pUp;
public:
	UpdateDeregistrationCommand() = default;
	~UpdateDeregistrationCommand() = default;
	UpdateDeregistrationCommand(const UpdateDeregistrationCommand&) = delete;
	UpdateDeregistrationCommand& operator = (const UpdateDeregistrationCommand&) = delete;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Constructor. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	///
	/// <param name="up">	[in,out] If non-null, the up. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	UpdateDeregistrationCommand(Updatable* up);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Executes this object. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void Execute() override;

};

#endif _UpdateDeregistrationCommand