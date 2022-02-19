#include "FuseHubWindow.h"

FuseHub::FuseHubWindow::FuseHubWindow()
{
	m_Window = nullptr;
	m_FuseHubApplication = nullptr;
}
FuseHub::FuseHubWindow::~FuseHubWindow() {}

void FuseHub::FuseHubWindow::Initialise()
{
	InitialiseWindow(1000, 550, "Fuse Hub");
	m_FuseHubApplication = new FuseHub::FuseHubApplication();

	MainLoop();

	delete m_FuseHubApplication;
}

void FuseHub::FuseHubWindow::ProcessInput()
{
	if (glfwGetKey(m_Window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(m_Window, true);
	}
}

void FuseHub::FuseHubWindow::Update(double deltaTime)
{

}

void FuseHub::FuseHubWindow::Render()
{
	BeginFrame();

	// Render the Hub
	m_FuseHubApplication->Render();

	EndFrame();
}