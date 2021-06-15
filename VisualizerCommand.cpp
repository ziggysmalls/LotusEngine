#include "VisualizerCommand.h"
#include "VisualizerAttorney.h"

VisualizerCommand::VisualizerCommand(Matrix m, Vect c)
	:mat(m), col(c)
{
}

void VisualizerCommand::Execute()
{
	VisualizerAttorney::CommandProcess::RenderBSphere(mat, col);
}

void VisualizerCommand::Update(Matrix m, Vect c)
{
	mat = m;
	col = c;
}