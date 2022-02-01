#include "GameViewport.h"

Editor::GameViewport::GameViewport() {}
Editor::GameViewport::~GameViewport() {}

void Editor::GameViewport::OnImGuiRender()
{
	ImGui::Begin("Game View", &GetActiveState(), ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);

	ImGui::End();
}