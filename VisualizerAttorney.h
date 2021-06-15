#ifndef _VisualizerAttorney
#define _VisualizerAttorney
#include "Visualizer.h"

class VisualizerAttorney
{
public:

	class GameLoop
	{
	private:
		friend class LotusEngine;
		static void Delete() { Visualizer::Delete(); };
		

	};
public:
	class VisualizeAll
	{
	private:
		friend class LotusEngine;
		static void EngineVisualizeAll() { Visualizer::VisualizeAll(); };

	};

public:
	class CommandProcess
	{
	private:
		friend class VisualizerCommand;
		friend class AABBVisualizerCommand;
		static void RenderBSphere(Matrix m, Vect c) { Visualizer::RenderBSphere(m, c); };
		static void RenderBox(Matrix m, Vect c) { Visualizer::RenderBox(m, c); };
	};
};

#endif _VisualizerAttorney
