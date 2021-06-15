#ifndef _RegistrationState
#define _RegistrationState

class RegistrationState
{
public:
	enum class RegStates
	{
		CURRENTLY_DEREGISTERED,
		PENDING_REGISTRATION,
		CURRENTLY_REGISTERED,
		PENDING_DEREGISTRATION
	};
};

#endif _RegistrationState