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

	m_Editor = new EditorUI::EditorWindow();
	m_Editor->SetupScene();

	MainLoop();
}

void EditorWindow::EditorWindow::ProcessInput()
{
	if (glfwGetKey(m_Window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(m_Window, true);
	}

	m_Editor->ProcessInput(m_Window);
}

void EditorWindow::EditorWindow::Update(float deltaTime)
{
	m_Editor->CalculateFPSFrametime();
}

void EditorWindow::EditorWindow::Render()
{
	// Create a new frame for ImGui
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	// Render the Editor
	m_Editor->RenderEditor();

	// Render ImGui
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}