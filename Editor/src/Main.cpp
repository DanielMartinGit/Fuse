#include "EditorWindow/Editor.h"
#include "Window/EditorWindow.h"
#include "../../Fuse Hub/src/Window/FuseHubWindow.h"

int main()
{
	srand((unsigned int)time(NULL));

	FuseHub::FuseHubWindow* FuseHubWindow = new FuseHub::FuseHubWindow();
	EditorWindow::EditorWindow* EditorWindow = new EditorWindow::EditorWindow();

	FuseHubWindow->Initialise();
	EditorWindow->Initialise();

	return 0;
}