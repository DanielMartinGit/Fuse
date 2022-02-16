#include "FuseHubWindow.h"

FuseHub::HubWindow::HubWindow()
{
	m_Window = nullptr;
	m_FuseHubApplication = nullptr;
}
FuseHub::HubWindow::~HubWindow() {}

void FuseHub::HubWindow::Initialise()
{
	InitialiseWindow(1000, 550, "Fuse Hub");
	m_FuseHubApplication = new FuseHub::FuseHubApplication();

	MainLoop();

	delete m_FuseHubApplication;
}

void FuseHub::HubWindow::ProcessInput()
{
	if (glfwGetKey(m_Window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(m_Window, true);
	}
}

void FuseHub::HubWindow::Update(double deltaTime)
{

}

void FuseHub::HubWindow::Render()
{
	BeginFrame();

	// Render the Hub
	m_FuseHubApplication->Render();

	EndFrame();
}