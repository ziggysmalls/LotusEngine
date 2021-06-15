#ifndef _AABBVisualizerCommandObjectPool
#define _AABBVisualizerCommandObjectPool

#include <stack>
#include <list>
#include "Matrix.h"
#include "Vect.h"

class AABBVisualizerCommand;
class AABBVisualizerCommandObjectPool
{
private:
	std::stack<AABBVisualizerCommand*> recycledItems;
	using ActiveVisualizerCommands = std::list<AABBVisualizerCommand*>;
	ActiveVisualizerCommands activeVisualizerCommands;

public:
	using ActiveVisualizerCommandRef = ActiveVisualizerCommands::iterator;

	// Big 4
	AABBVisualizerCommandObjectPool();
	AABBVisualizerCommandObjectPool(const AABBVisualizerCommandObjectPool&) = delete;
	AABBVisualizerCommandObjectPool& operator=(const AABBVisualizerCommandObjectPool&) = delete;
	~AABBVisualizerCommandObjectPool();


	AABBVisualizerCommand* GetCmd(Matrix m, Vect v);
	void ReturnCmd(AABBVisualizerCommand* b);

};

#endif _VisCmdAABBObjectPool