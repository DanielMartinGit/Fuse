#include "AssetBrowser.h"

Fuse::AssetBrowser::AssetBrowser() {}
Fuse::AssetBrowser::~AssetBrowser() {}

void Fuse::AssetBrowser::OnImGuiRender()
{
	ImGui::Begin("Asset Browser", &GetActiveState());
	ImGui::Button("Refresh", ImVec2(100, 20));
	ImGui::Separator();

	ImGui::End();
}