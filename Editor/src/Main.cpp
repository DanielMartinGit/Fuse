//#include "../../FuseHub/src/Application/FuseHubApplication.h"
#include "EditorApp/EditorApplication.h"

int main()
{
	srand((unsigned int)time(NULL));

	//FuseHub::FuseHubApplication* hubApp = new FuseHub::FuseHubApplication();
	//hubApp->Initialise();

	Editor::EditorApplication* editorApp = new Editor::EditorApplication();
	editorApp->Initialise();
	
	return 0;
}