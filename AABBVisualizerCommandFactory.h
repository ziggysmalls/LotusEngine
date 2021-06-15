#ifndef _VisCmdAABBFactory
#define _VisCmdAABBFactory

#include "AzulCore.h"

class AABBVisualizerCommandObjectPool;
class AABBVisualizerCommand;
class AABBVisualizerCommandFactory
{
private:

	static AABBVisualizerCommandFactory* InstancePtr;				

	AABBVisualizerCommandFactory();									
	AABBVisualizerCommandFactory(const AABBVisualizerCommandFactory&) = delete;				
	AABBVisualizerCommandFactory& operator=(const AABBVisualizerCommandFactory&) = delete;	
	~AABBVisualizerCommandFactory() = default;									

	static AABBVisualizerCommandFactory& Instance()					
	{
		if (!InstancePtr)
			InstancePtr = new AABBVisualizerCommandFactory;
		return *InstancePtr;
	};

	AABBVisualizerCommandObjectPool* visualizerOP;

	AABBVisualizerCommand* privCreateCmd(Matrix m, Vect r);
	void privRecycleCmd(AABBVisualizerCommand* cmd);
	void privDelete();

public:
	static AABBVisualizerCommand* CreateCmd(Matrix m, Vect r) { return Instance().privCreateCmd(m, r); };
	static void RecycleCmd(AABBVisualizerCommand* cmd) { Instance().privRecycleCmd(cmd); };
	static void Delete() { Instance().privDelete(); };
};

#endif _VisCmdAABBFactory
