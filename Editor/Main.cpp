#include "Editor/Window/Window.h"
#include "Editor/EditorWindow/Editor.h"

int main()
{
	srand((unsigned int)time(NULL));

	Fuse::Editor editor;
	Fuse::Window window(editor);

	window.Initialise();

	return 0;
}