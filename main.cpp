
#include "LotusEngine.h"

int CALLBACK WinMain(HINSTANCE , HINSTANCE ,  LPSTR , int)                  {          
   

	// start the game
	LotusEngine::Run();
	// "clean-up"... (not really for these demos)
	LotusEngine::Delete();

	return 0;                                       
}

