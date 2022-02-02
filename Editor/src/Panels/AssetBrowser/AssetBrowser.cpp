#include "AssetBrowser.h"

Editor::AssetBrowser::AssetBrowser()
{
	m_CurrentDirectory = m_AssetsDirectory;
	m_Refresh = false;
}

Editor::AssetBrowser::~AssetBrowser() {}

void Editor::AssetBrowser::OnImGuiRender()
{
	ImGui::Begin("Asset Browser", &GetActiveState());

	if (m_AssetsDirectory != "")
	{
		if (m_CurrentDirectory != std::filesystem::path(m_AssetsDirectory))
		{
			if (ImGui::Button("<--"))
			{
				m_CurrentDirectory = m_CurrentDirectory.parent_path();
			}
		}

		ImGui::SameLine();
		ImGui::Button("Refresh", ImVec2(100, 20));
		ImGui::Separator();

		for (auto& directoryEntry : std::filesystem::directory_iterator(m_CurrentDirectory))
		{
			auto relativePath = std::filesystem::relative(directoryEntry.path(), m_AssetsDirectory);
			std::string filename = relativePath.filename().string();

			if (directoryEntry.is_directory())
			{
				if (ImGui::Button(filename.c_str()))
				{
					m_CurrentDirectory /= directoryEntry.path().filename();
				}
			}
			else
			{
				if (ImGui::Button(filename.c_str()))
				{	
				}
			}
		}
	}

	ImGui::End();
}