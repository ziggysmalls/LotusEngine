#ifndef _VisualizerCommandObjectPool
#define _VisualizerCommandObjectPool

#include <stack>
#include <list>
#include "Matrix.h"
#include "Vect.h"

class VisualizerCommand;
class VisualizerCommandObjectPool
{
private:
	std::stack<VisualizerCommand*> recycledItems;
	using ActiveVisualizerCommands = std::list<VisualizerCommand*>;
	ActiveVisualizerCommands activeVisualizerCommands;

public:
	using ActiveVisualizerCommandRef = ActiveVisualizerCommands::iterator;

	// Big 4
	VisualizerCommandObjectPool();
	VisualizerCommandObjectPool(const VisualizerCommandObjectPool&) = delete;
	VisualizerCommandObjectPool& operator=(const VisualizerCommandObjectPool&) = delete;
	~VisualizerCommandObjectPool();


	VisualizerCommand* GetCmd(Matrix m, Vect v);
	void ReturnCmd(VisualizerCommand* b);

};

#endif _VisualizerCommandObjectPool