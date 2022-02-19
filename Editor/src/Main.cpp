#include "../../FuseHub/src/Window/FuseHubWindow.h"
#include "EditorWindow/EditorWindow.h"

int main()
{
	srand((unsigned int)time(NULL));

	FuseHub::FuseHubWindow* hubWindow = new FuseHub::FuseHubWindow();
	hubWindow->Initialise();
	
	//EditorWindow::EditorWindow* editorWindow = new EditorWindow::EditorWindow();
	//editorWindow->Initialise();

	return 0;
}