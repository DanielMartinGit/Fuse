#include "EditorApplication.h"

Editor::EditorApplication::EditorApplication()
{ 
	m_Window = nullptr;
	m_Editor = nullptr;
}
Editor::EditorApplication::~EditorApplication() {}

void Editor::EditorApplication::Initialise()
{
	InitialiseWindow(1920, 1080, "Fuse");

	m_Editor = new EditorUI::EditorApplication();
	m_Editor->SetupScene();

	MainWindowLoop();
}

void Editor::EditorApplication::MainWindowLoop()
{
	while (!glfwWindowShouldClose(m_Window))
	{
		// Input
		ProcessInput();

		// Update
		Update(Fuse::Time::GetDeltaTime());

		// Render
		Render();

		// Check events and Swap Buffers
		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}

	DestroyWindow();
}

void Editor::EditorApplication::ProcessInput()
{
	if (glfwGetKey(m_Window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(m_Window, true);
	}

	m_Editor->ProcessInput(m_Window);
}

void Editor::EditorApplication::Update(double deltaTime)
{
	m_Editor->CalculateFPSFrametime();
}

void Editor::EditorApplication::Render()
{
	BeginFrame();

	// Render the Editor
	m_Editor->Render();
	
	EndFrame();
}