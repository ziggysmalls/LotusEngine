#include "AABBVisualizerCommandObjectPool.h"
#include "AABBVisualizerCommand.h"

AABBVisualizerCommandObjectPool::AABBVisualizerCommandObjectPool()
{
}

AABBVisualizerCommandObjectPool::~AABBVisualizerCommandObjectPool()
{
	Trace::out("Deleting %i Recycled VisualizerCommands \n", recycledItems.size());

	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}

	Trace::out("Deleting %i Active VisualizerCommands \n", activeVisualizerCommands.size());

	for (AABBVisualizerCommand* pB : activeVisualizerCommands)
	{
		delete pB;
	}

}

AABBVisualizerCommand* AABBVisualizerCommandObjectPool::GetCmd(Matrix m, Vect v)
{
	AABBVisualizerCommand* b;
	if (recycledItems.empty())
	{
		b = new AABBVisualizerCommand(m, v);

		// Register Active VisualizerCommand
		b->pMyDeleteRef = activeVisualizerCommands.insert(activeVisualizerCommands.end(), b);

		Trace::out("New VisualizerCommand AABB Created \n");
	}
	else
	{
		b = recycledItems.top();
		recycledItems.pop();

		b->Update(m, v);
		// Register Active VisualizerCommand
		b->pMyDeleteRef = activeVisualizerCommands.insert(activeVisualizerCommands.end(), b);

		//Trace::out("Recycled VisualizerCommand Created \n");
	}

	return b;
}


void AABBVisualizerCommandObjectPool::ReturnCmd(AABBVisualizerCommand* b)
{
	// Deregister cmd from active list
	activeVisualizerCommands.erase(b->pMyDeleteRef);

	// Recycle VisualizerCommand
	recycledItems.push(b);
}