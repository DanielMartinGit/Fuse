#include "EditorWindow/Editor.h"
#include "Window/Window.h"

int main()
{
	srand((unsigned int)time(NULL));

	Editor::EditorWindow* editor = new Editor::EditorWindow();
	Utils::Window* window = new Utils::Window(*editor);

	window->Initialise();

	return 0;
}