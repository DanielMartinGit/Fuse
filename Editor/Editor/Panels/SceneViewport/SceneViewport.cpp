#include "SceneViewport.h"

Fuse::SceneViewport::SceneViewport() {}
Fuse::SceneViewport::~SceneViewport() {}

void Fuse::SceneViewport::OnImGuiRender()
{
	ImGui::Begin("Scene View", &GetActiveState(), ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoTitleBar);

	// Render ImGui Texture here with FBO
	ImVec2 vWindowSize = ImGui::GetWindowSize();

	ImGui::Image((ImTextureID)Fuse::SceneManager::GetSceneFBO(), vWindowSize);

	ImGui::End();
}