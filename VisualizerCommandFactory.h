#ifndef _VisualizerCommandFactory
#define _VisualizerCommandFactory

#include "AzulCore.h"

class VisualizerCommandObjectPool;
class VisualizerCommand;
class VisualizerCommandFactory
{
private:

	static VisualizerCommandFactory* InstancePtr;				

	VisualizerCommandFactory();					
	VisualizerCommandFactory(const VisualizerCommandFactory&) = delete;			
	VisualizerCommandFactory& operator=(const VisualizerCommandFactory&) = delete;	
	~VisualizerCommandFactory() = default;						

	static VisualizerCommandFactory& Instance()				
	{
		if (!InstancePtr)
			InstancePtr = new VisualizerCommandFactory;
		return *InstancePtr;
	};

	VisualizerCommandObjectPool* visualizerOP;

	VisualizerCommand* privCreateCmd(Matrix m, Vect r);
	void privRecycleCmd(VisualizerCommand* cmd);
	void privDelete();

public:
	static VisualizerCommand* CreateCmd(Matrix m, Vect r) { return Instance().privCreateCmd(m, r); };
	static void RecycleCmd(VisualizerCommand* cmd) { Instance().privRecycleCmd(cmd); };
	static void Delete() { Instance().privDelete(); };
};

#endif _VisualizerCommandFactory
