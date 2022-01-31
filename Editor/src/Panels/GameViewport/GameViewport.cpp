#include "GameViewport.h"

Fuse::GameViewport::GameViewport() {}
Fuse::GameViewport::~GameViewport() {}

void Fuse::GameViewport::OnImGuiRender()
{
	ImGui::Begin("Game View", &GetActiveState(), ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);

	ImGui::End();
}