#include "SceneViewport.h"

Editor::SceneViewport::SceneViewport() {}
Editor::SceneViewport::~SceneViewport() {}

void Editor::SceneViewport::OnImGuiRender()
{
	ImGui::Begin("Scene View", &GetActiveState(), ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoTitleBar);

	ImGui::Begin("##Controls", &GetActiveState(), ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoResize);
	
	ImGui::Button("move", ImVec2(100, 20));
	ImGui::SameLine();
	ImGui::Button("rotate", ImVec2(100, 20));
	ImGui::SameLine();
	ImGui::Button("scale", ImVec2(100, 20));

	ImGui::End();

	// Render ImGui Texture here with FBO
	ImVec2 vWindowSize = ImGui::GetWindowSize();

	ImGui::Image((ImTextureID)Fuse::SceneManager::GetSceneFBO(), vWindowSize);

	ImGui::End();
}