#include "VisualizerCommandFactory.h"
#include "VisualizerCommand.h"
#include "VisualizerCommandObjectPool.h"

VisualizerCommandFactory* VisualizerCommandFactory::InstancePtr = nullptr;

VisualizerCommandFactory::VisualizerCommandFactory()
{
	visualizerOP = new VisualizerCommandObjectPool();
};

VisualizerCommand* VisualizerCommandFactory::privCreateCmd(Matrix m, Vect r)
{
	VisualizerCommand* c = visualizerOP->GetCmd(m, r);
	return c;
}

void VisualizerCommandFactory::privRecycleCmd(VisualizerCommand* cmd)
{
	visualizerOP->ReturnCmd(cmd);
}

void VisualizerCommandFactory::privDelete()
{
	delete visualizerOP;
	delete InstancePtr;
	InstancePtr = nullptr;
}
