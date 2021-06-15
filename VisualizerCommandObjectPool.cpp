#include "VisualizerCommandObjectPool.h"
#include "VisualizerCommand.h"

VisualizerCommandObjectPool::VisualizerCommandObjectPool()
{
}

VisualizerCommandObjectPool::~VisualizerCommandObjectPool()
{


	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}

	for (VisualizerCommand* pB : activeVisualizerCommands)
	{
		delete pB;
	}

}

VisualizerCommand* VisualizerCommandObjectPool::GetCmd(Matrix m, Vect v)
{
	VisualizerCommand* b;
	if (recycledItems.empty())
	{
		b = new VisualizerCommand(m, v);

		// Register Active VisualizerCommand
		b->pMyDeleteRef = activeVisualizerCommands.insert(activeVisualizerCommands.end(), b);

	
	}
	else //if (recycledItems.size())
	{
		b = recycledItems.top();
		recycledItems.pop();

		b->Update(m, v);
		// Register Active VisualizerCommand
		b->pMyDeleteRef = activeVisualizerCommands.insert(activeVisualizerCommands.end(), b);

	}

	return b;
}


void VisualizerCommandObjectPool::ReturnCmd(VisualizerCommand* b)
{
	// Deregister from active list
	activeVisualizerCommands.erase(b->pMyDeleteRef);

	// Recycle VisualizerCommand
	recycledItems.push(b);
}