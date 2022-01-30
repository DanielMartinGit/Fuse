#include "../Editor/Editor/Window/Window.h"
#include "../Editor/Editor/EditorWindow/Editor.h"

int main()
{
	srand((unsigned int)time(NULL));

	Fuse::Editor* editor = new Fuse::Editor();
	Fuse::Window* window = new Fuse::Window(*editor);
	
	window->Initialise();

	return 0;
}