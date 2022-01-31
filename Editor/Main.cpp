#include "src/EditorWindow/Editor.h"
#include "src/Window/Window.h"

int main()
{
	srand((unsigned int)time(NULL));

	Fuse::Editor* editor = new Fuse::Editor();
	Fuse::Window* window = new Fuse::Window(*editor);
	
	window->Initialise();

	return 0;
}