#include "AssetBrowser.h"

Editor::AssetBrowser::AssetBrowser() {}
Editor::AssetBrowser::~AssetBrowser() {}

void Editor::AssetBrowser::OnImGuiRender()
{
	ImGui::Begin("Asset Browser", &GetActiveState());
	ImGui::Button("Refresh", ImVec2(100, 20));
	ImGui::Separator();

	ImGui::End();
}