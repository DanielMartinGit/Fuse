#include "BaseWindow.h"

Fuse::Window::Window()
{ 
	m_Window = nullptr; 
	m_Initialised = false;
}
Fuse::Window::~Window() {}

void Fuse::Window::InitialiseWindow(uint32_t width, uint32_t height, const char* windowTitle)
{
	m_WindowWidth = width;
	m_WindowHeight = height;
	m_WindowTitle = windowTitle;

	if (!m_Initialised)
	{
		m_InitLayer.InitialiseOpenGL();
		m_Window = m_InitLayer.InitialiseWindow(m_WindowWidth, m_WindowHeight, m_WindowTitle);
		InitialiseLayers();
		m_InitLayer.InitialiseGLAD();

		m_InitLayer.InitialiseImGui(m_Window, m_EditorTheme, m_GLSLVersion);

		m_Initialised = true;
	}
}

void Fuse::Window::InitialiseLayers()
{
	m_InputLayer.InitialiseCallback(m_Window);
	m_InputLayer.OnCreate();

	m_Layers.emplace_back(m_InputLayer);
}

void Fuse::Window::MainLoop()
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

	// Destroy the Input Layer
	m_InputLayer.OnDestroy();

	// Shutdown ImGui and destroy the GLFW window, then terminate GLFW altogether
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	// Destroy the Window and Terminate GLFW
	glfwDestroyWindow(m_Window);
	glfwTerminate();
}

void Fuse::Window::BeginFrame()
{
	// Create a new frame for ImGui
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void Fuse::Window::EndFrame()
{
	// Render ImGui
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void Fuse::Window::Initialise() {}
void Fuse::Window::ProcessInput() {}
void Fuse::Window::Update(double deltaTime) {}
void Fuse::Window::Render() {}