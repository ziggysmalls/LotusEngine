// Ezequiel Arrieta
// GAM 374 
// Lotus


#ifndef _UpdateRegistrationCommand
#define _UpdateRegistrationCommand

#include "CommandBase.h"
#include "Updatable.h"

class UpdateRegistrationCommand : public CommandBase
{
private:
	Updatable* pUp;

public:
	UpdateRegistrationCommand() = default;
	~UpdateRegistrationCommand() = default;
	UpdateRegistrationCommand(const UpdateRegistrationCommand&) = delete;
	UpdateRegistrationCommand& operator = (const UpdateRegistrationCommand&) = delete;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Constructor. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	///
	/// <param name="up">	[in,out] If non-null, the up. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	UpdateRegistrationCommand(Updatable* up);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Executes this object. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void Execute() override;

};

#endif _UpdateRegistrationCommand