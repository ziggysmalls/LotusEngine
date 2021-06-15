#include "AABBVisualizerCommand.h"
#include "VisualizerAttorney.h"
#include "AABBVisualizerCommandFactory.h"

AABBVisualizerCommand::AABBVisualizerCommand(Matrix m, Vect c)
	:mat(m), col(c)
{
}

void AABBVisualizerCommand::Execute()
{
	VisualizerAttorney::CommandProcess::RenderBox(mat, col);
	AABBVisualizerCommandFactory::RecycleCmd(this);  // Recycle the command after is executed :) 
}

void AABBVisualizerCommand::Update(Matrix m, Vect c)
{
	mat = m;
	col = c;
}