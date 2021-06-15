#pragma once
class VisualizerCommandBase
{
public:
	VisualizerCommandBase() = default;
	virtual ~VisualizerCommandBase() {};
	VisualizerCommandBase(const VisualizerCommandBase&) = delete;
	VisualizerCommandBase& operator = (const VisualizerCommandBase&) = delete;


	virtual void Execute() = 0;
};