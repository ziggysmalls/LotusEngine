#ifndef _AABBVisualizerCommand
#define _AABBVisualizerCommand

#include "VisualizerCommandBase.h"
#include "Matrix.h"
#include "Vect.h"
#include "AABBVisualizerCommandObjectPool.h"

class AABBVisualizerCommand : public VisualizerCommandBase
{
	Matrix mat;
	Vect col;
public:
	AABBVisualizerCommand() = default;
	virtual ~AABBVisualizerCommand() = default;
	AABBVisualizerCommand(const AABBVisualizerCommand&) = delete;
	AABBVisualizerCommand& operator = (const AABBVisualizerCommand&) = delete;

	AABBVisualizerCommandObjectPool::ActiveVisualizerCommandRef pMyDeleteRef;

	AABBVisualizerCommand(Matrix m, Vect c);

	void Update(Matrix m, Vect c);

	virtual void Execute() override;
};

#endif _VisualizerCommandAABB
