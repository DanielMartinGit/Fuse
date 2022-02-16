#include "../../FuseHub/src/Window/FuseHubWindow.h"
#include "Window/EditorWindow.h"

int main()
{
	srand((unsigned int)time(NULL));

	//FuseHub::HubWindow* FuseHubWindow = new FuseHub::HubWindow();
	//FuseHubWindow->Initialise();
	
	EditorWindow::EditorWindow* editorWindow = new EditorWindow::EditorWindow();
	editorWindow->Initialise();

	return 0;
}