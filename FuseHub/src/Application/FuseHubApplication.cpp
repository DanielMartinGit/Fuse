#include "FuseHubApplication.h"

FuseHub::FuseHubApplication::FuseHubApplication()
{
	m_DockSpaceID = 0;

	m_WindowFlags |= ImGuiWindowFlags_MenuBar | 
	ImGuiWindowFlags_NoResize | 
	ImGuiWindowFlags_NoMove | 
	ImGuiWindowFlags_NoCollapse | 
	ImGuiWindowFlags_NoBringToFrontOnFocus | 
	ImGuiWindowFlags_NoTitleBar | 
	ImGuiWindowFlags_NoDocking;

	m_Option = m_HubOptions::PROJECTS;
}
FuseHub::FuseHubApplication::~FuseHubApplication() {}

void FuseHub::FuseHubApplication::Initialise()
{
	InitialiseWindow(1000, 550, "Fuse Hub");
	MainLoop();
}

void FuseHub::FuseHubApplication::MainLoop()
{
	while (!glfwWindowShouldClose(m_Window))
	{
		ProcessInput();

		Update(Fuse::Time::GetDeltaTime());

		Render();

		// Check events and Swap Buffers
		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}

	DestroyWindow();
}

void FuseHub::FuseHubApplication::ProcessInput()
{
	if (glfwGetKey(m_Window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(m_Window, true);
	}
}
void FuseHub::FuseHubApplication::Update(double deltaTime) {}

void FuseHub::FuseHubApplication::Render() 
{
	ImGui::Begin("Hub", 0, m_WindowFlags);

	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
	ImVec2 vWindowSize = ImGui::GetMainViewport()->Size;
	ImVec2 vPos0 = ImGui::GetMainViewport()->Pos;

	ImGui::SetWindowPos(ImVec2((float)vPos0.x, (float)vPos0.y), ImGuiCond_Always);
	ImGui::SetWindowSize(ImVec2((float)vWindowSize.x, (float)vWindowSize.y), ImGuiCond_Always);
	ImGui::PopStyleVar();

	m_DockSpaceID = ImGui::GetID("MainDockSpace");
	ImGui::DockSpace(m_DockSpaceID, ImVec2(0.f, 0.f), ImGuiDockNodeFlags_None | ImGuiDockNodeFlags_PassthruCentralNode);

	switch (m_Option)
	{
		case m_HubOptions::PROJECTS:
		{
			OnImGuiRenderProjects();
		}
			break;
		case m_HubOptions::INSTALLS:
		{
			OnImGuiRenderInstalls();
		}
			break;
		case m_HubOptions::CREATEPROJECT:
		{
			OnImGuiRenderCreateProject();
		}
			break;
		case m_HubOptions::LOADPROJECT:
		{
			OnImGuiRenderLoadProject();
		}
			break;
		default:
			m_Option = m_HubOptions::PROJECTS;
	}

	ImGui::End();
}

void FuseHub::FuseHubApplication::OnImGuiRenderProjects()
{

}

void FuseHub::FuseHubApplication::OnImGuiRenderInstalls()
{

}

void FuseHub::FuseHubApplication::OnImGuiRenderCreateProject()
{

}

void FuseHub::FuseHubApplication::OnImGuiRenderLoadProject()
{

}