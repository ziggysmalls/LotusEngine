#include "Visualizer.h"
#include "../src/Lotus Engine/ModelManager.h"
#include "../src/Lotus Engine/ShaderManager.h" 
#include "SceneManager.h"
#include "VisualizerCommandFactory.h"
#include "AABBVisualizerCommandFactory.h"
Visualizer* Visualizer::InstancePtr = nullptr;
Vect Visualizer::DEFAULT_COLOR = Vect(0.0f, 0.0f, 1.0f, 1.0f);
Vect Visualizer::DEFAULT_COLOR2 = Color::WhiteSmoke;
Visualizer::Visualizer()
{
	WFUnitSphere = new GraphicsObject_WireframeConstantColor(ModelManager::Get("Sphere"), ShaderManager::Get("ColorConstant"), DEFAULT_COLOR);
	WFBox = new GraphicsObject_WireframeConstantColor(ModelManager::Get("Box"), ShaderManager::Get("ColorConstant"), DEFAULT_COLOR2);
}

void Visualizer::privateDelete()
{
	VisualizerCommandFactory::Delete();
	AABBVisualizerCommandFactory::Delete();
	delete WFUnitSphere;
	delete WFBox;
	delete InstancePtr;
	InstancePtr = nullptr;
}

void Visualizer::privToggle()
{
	bToggle = !bToggle;
}

void Visualizer::privShowSphere(const CollisionVolumeBSphere& S, const Vect& col)
{
	if (bToggle)
	{
		const Vect vBSSize = S.GetRadius() * Vect(1, 1, 1);
		Matrix m = Matrix(SCALE, vBSSize) * Matrix(TRANS, S.GetCenter());

		VisualizerListCol.insert(VisualizerListCol.end(), S.GetCommand(m, col));
	}
}

void Visualizer::privBox(const Vect& center, const Vect& col, float scale)
{
	if (bToggle)
	{
		Matrix m = Matrix(SCALE, Vect(scale, scale, scale)) * Matrix(TRANS, center);

		VisualizerListCol.insert(VisualizerListCol.end(), AABBVisualizerCommandFactory::CreateCmd(m, col));
	}
}


void Visualizer::privRenderBSphere(Matrix& S, const Vect& col)
{
	WFUnitSphere->SetWorld(S);
	WFUnitSphere->SetColor(col);

	WFUnitSphere->Render(SceneManager::GetCameraManager()->GetCurrentCamera());
}

void Visualizer::privRenderBox(Matrix& S, const Vect& col)
{
	WFBox->SetWorld(S);
	WFBox->SetColor(col);
	WFBox->Render(SceneManager::GetCameraManager()->GetCurrentCamera());
}

void Visualizer::privateVisualizeAll()
{
	for (VisualCmdCol::iterator it = VisualizerListCol.begin(); it != VisualizerListCol.end(); it++)
	{
		(*it)->Execute();
	}

	VisualizerListCol.clear();
}

void Visualizer::privShowCVolume(const CollisionVolume& cv, const Vect& c, bool bCol)
{
	if (bToggle)
	{
		cv.DebugView(c, bCol);
	}
}

void Visualizer::privShowAABB(const CollisionVolumeAABB& ab, const Vect& c)
{
	if (bToggle)
	{
		// Get Scale
		const Vect abScale = ab.GetMaxAABB() - ab.GetMinAABB();

		// Apply Matrix
		Matrix m = Matrix(SCALE, abScale) * Matrix(TRANS, (0.5f * (ab.GetMinAABB() + ab.GetMaxAABB())));

		// Send  AABB visualizer command 
		VisualizerListCol.insert(VisualizerListCol.end(), AABBVisualizerCommandFactory::CreateCmd(m, c));

	}
}

void Visualizer::privShowAABB(const Vect& min, const Vect& max, const Vect& c)
{
	if (bToggle)
	{
		// Get Scale
		const Vect abScale = max - min;

		// Apply Matrix
		Matrix m = Matrix(SCALE, abScale) * Matrix(TRANS, (0.5f * (min + max)));

		// Send  AABB visualizer command 
		VisualizerListCol.insert(VisualizerListCol.end(), AABBVisualizerCommandFactory::CreateCmd(m, c));
	}
}


void Visualizer::privShowOBB(const CollisionVolumeOBB& ab, const Vect& c)
{
	if (bToggle)
	{
		// Get Scale
		const Vect abScale = ab.GetMaxOBB() - ab.GetMinOBB();

		// Apply Matrix
		Matrix m = Matrix(SCALE, abScale) * Matrix(TRANS, (0.5f * (ab.GetMinOBB() + ab.GetMaxOBB())));
		m = m * ab.GetWorld();

		// Send  AABB visualizer command 
		VisualizerListCol.insert(VisualizerListCol.end(), AABBVisualizerCommandFactory::CreateCmd(m, c));
	}
}



void Visualizer::privShowVerticalLine(const Vect& orig, const float len, const Vect& col)
{
	if (bToggle)
	{
		Vect Center = orig - Vect(0, len / 2, 0);

		// Apply Matrix
		Matrix m = Matrix(SCALE, Vect(0.05f, abs(len), 0.05f)) * Matrix(TRANS, Center);

		// Send  AABB visualizer command 
		VisualizerListCol.insert(VisualizerListCol.end(), AABBVisualizerCommandFactory::CreateCmd(m, col));
	}

}
