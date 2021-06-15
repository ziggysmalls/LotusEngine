#ifndef _VisualizerCommand
#define _VisualizerCommand
#include "VisualizerCommandBase.h"
#include "Matrix.h"
#include "Vect.h"
#include "VisualizerCommandObjectPool.h"
class VisualizerCommand : public VisualizerCommandBase
{
	Matrix mat;
	Vect  col;

public:
	VisualizerCommand() = default;
	~VisualizerCommand() = default;
	VisualizerCommand(const VisualizerCommand&) = delete;
	VisualizerCommand& operator = (const VisualizerCommand&) = delete;
	VisualizerCommandObjectPool::ActiveVisualizerCommandRef pMyDeleteRef;
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Constructor. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	///
	/// <param name="m">	A Matrix to process. </param>
	/// <param name="c">	A Vect to process. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	VisualizerCommand(Matrix m, Vect c);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Updates this object. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	///
	/// <param name="m">	A Matrix to process. </param>
	/// <param name="c">	A Vect to process. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void Update(Matrix m, Vect c);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Executes this object. </summary>
	///
	/// <remarks>	Ezequiel Arrieta, 3/3/2021. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void Execute() override;

};
#endif _VisualizerCommand
