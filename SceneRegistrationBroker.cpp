#include "SceneRegistrationBroker.h"

void SceneRegistrationBroker::addCommand(CommandBase* cmd)
{
	lstCommands.push_back(cmd);
	
}

void SceneRegistrationBroker::ExecuteCommands()
{
	for (CommandList::const_iterator it = lstCommands.begin(); it != lstCommands.end(); ++it)
	{
		CommandBase* c = *it;
		c->Execute();
	}

	lstCommands.clear();

	
}
SceneRegistrationBroker::~SceneRegistrationBroker()
{
	if (!lstCommands.empty())
		lstCommands.clear();
}