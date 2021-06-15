#include "AABBVisualizerCommandFactory.h"
#include "VisualizerCommand.h"
#include "AABBVisualizerCommandObjectPool.h"

AABBVisualizerCommandFactory* AABBVisualizerCommandFactory::InstancePtr = nullptr;

AABBVisualizerCommandFactory::AABBVisualizerCommandFactory()
{
	visualizerOP = new AABBVisualizerCommandObjectPool();
};

AABBVisualizerCommand* AABBVisualizerCommandFactory::privCreateCmd(Matrix m, Vect r)
{
	AABBVisualizerCommand* c = visualizerOP->GetCmd(m, r);

	//c->Initialize(m,r);  

	return c;
}

void AABBVisualizerCommandFactory::privRecycleCmd(AABBVisualizerCommand* cmd)
{
	visualizerOP->ReturnCmd(cmd);
	//Trace::out("Visualizer Command Returned to be Recycled \n");
}

void AABBVisualizerCommandFactory::privDelete()
{
	delete visualizerOP;
	delete InstancePtr;
	InstancePtr = nullptr;
}