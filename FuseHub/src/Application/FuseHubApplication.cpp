#include "FuseHubApplication.h"

FuseHub::FuseHubApplication::FuseHubApplication()
{ 
	m_Option = m_HubOptions::PROJECTS;
	m_DockSpaceID = 0;
}
FuseHub::FuseHubApplication::~FuseHubApplication() {}

void FuseHub::FuseHubApplication::Render()
{
	ImGui::Begin("Hub", 0, ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoDocking);

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