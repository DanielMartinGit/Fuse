#include "EditorWindow.h"

EditorWindow::EditorWindow::EditorWindow()
{ 
	m_Window = nullptr;
	m_Editor = nullptr;
}
EditorWindow::EditorWindow::~EditorWindow() {}

void EditorWindow::EditorWindow::Initialise()
{
	InitialiseWindow(1920, 1080, "Fuse Editor");

	m_Editor = new EditorUI::EditorApplication();
	m_Editor->SetupScene();

	MainLoop();

	delete m_Editor;
}

void EditorWindow::EditorWindow::ProcessInput()
{
	if (glfwGetKey(m_Window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(m_Window, true);
	}

	m_Editor->ProcessInput(m_Window);
}

void EditorWindow::EditorWindow::Update(double deltaTime)
{
	m_Editor->CalculateFPSFrametime();
}

void EditorWindow::EditorWindow::Render()
{
	BeginFrame();

	// Render the Editor
	m_Editor->Render();
	
	EndFrame();
}