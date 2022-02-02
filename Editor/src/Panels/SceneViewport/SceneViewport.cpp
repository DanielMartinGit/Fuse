#include "SceneViewport.h"

Editor::SceneViewport::SceneViewport() {}
Editor::SceneViewport::~SceneViewport() {}

void Editor::SceneViewport::OnImGuiRender()
{
	ImGui::Begin("Scene View", &GetActiveState(), ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoTitleBar);

	ImGui::Begin("##Controls", &GetActiveState(), ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoResize);
	ImGui::SetWindowSize(ImVec2(132, 47));
	
	ImGui::ImageButton((ImTextureID)m_MoveIcon, ImVec2(25, 25));
	ImGui::SameLine();
	ImGui::ImageButton((ImTextureID)m_RotateIcon, ImVec2(25, 25));
	ImGui::SameLine();
	ImGui::ImageButton((ImTextureID)m_ScaleIcon, ImVec2(25, 25));

	ImGui::End();

	// Render ImGui Texture here with FBO
	ImVec2 vWindowSize = ImGui::GetWindowSize();

	ImGui::Image((ImTextureID)Fuse::SceneManager::GetSceneFBO(), vWindowSize);

	ImGui::End();
}