// Ezequiel Arrieta
// GAM 374 
// Lotus

#ifndef _SceneRegistrationBroker
#define _SceneRegistrationBroker

#include "CommandBase.h"
#include <list>

class SceneRegistrationBroker
{
private:
	using CommandList = std::list<CommandBase*>;
	CommandList lstCommands;

public:
	SceneRegistrationBroker() = default;
	~SceneRegistrationBroker();
	SceneRegistrationBroker(const SceneRegistrationBroker&) = delete;
	SceneRegistrationBroker& operator = (const SceneRegistrationBroker&) = delete;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Adds a command. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	///
	/// <param name="cmd">	[in,out] If non-null, the command. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void addCommand(CommandBase* cmd);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Executes the 'commands' operation. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void ExecuteCommands();

};

#endif _SceneRegistrationBroker
