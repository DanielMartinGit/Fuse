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
		if (ImGui::ImageButton((ImTextureID)m_BackButton, ImVec2(25, 25)))
		{
			if (m_CurrentDirectory != std::filesystem::path(m_AssetsDirectory))
			{
				m_CurrentDirectory = m_CurrentDirectory.parent_path();
			}
		}

		ImGui::SameLine();
		ImGui::ImageButton((ImTextureID)m_RefreshButton, ImVec2(25, 25));
		ImGui::Separator();

		if (!m_isCompact)
		{
			m_ThumbnailSize = 60.0f;
			m_SameLineText = false;
			m_PanelWidth = ImGui::GetContentRegionAvail().x;
			m_CellSize = m_ThumbnailSize + m_ThumbnailPadding;

			m_ColumnCount = (int)(m_PanelWidth / m_CellSize);

			if (m_ColumnCount < 1) m_ColumnCount = 1;

			ImGui::Columns(m_ColumnCount, 0, false);
		}
		else
		{
			m_ColumnCount = 1;
			m_SameLineText = true;
			m_ThumbnailSize = 20.0f;
			ImGui::Columns(m_ColumnCount, 0, false);
		}

		try
		{
			for (auto& directoryEntry : std::filesystem::directory_iterator(m_CurrentDirectory))
			{
				auto relativePath = std::filesystem::relative(directoryEntry.path(), m_AssetsDirectory);
				std::string filename = relativePath.filename().string();

				if (directoryEntry.is_directory())
				{
					if (ImGui::ImageButton((ImTextureID)m_FolderIcon, ImVec2(m_ThumbnailSize, m_ThumbnailSize)))
					{
						m_CurrentDirectory /= directoryEntry.path().filename();
					}
				}
				else if(directoryEntry.is_regular_file() && std::filesystem::path(directoryEntry).extension() == ".png")
				{
					if (ImGui::ImageButton((ImTextureID)m_PngIcon, ImVec2(m_ThumbnailSize, m_ThumbnailSize)))
					{

					}
				}
				else if (directoryEntry.is_regular_file() && std::filesystem::path(directoryEntry).extension() == ".scene")
				{
					if (ImGui::ImageButton((ImTextureID)m_SceneIcon, ImVec2(m_ThumbnailSize, m_ThumbnailSize)))
					{
						
					}
				}

				if (!m_SameLineText)
				{
					ImGui::Text(filename.c_str());
				}
				else
				{
					ImGui::SameLine();
					ImGui::Text(filename.c_str());
				}

				ImGui::NextColumn();
			}

			ImGui::Columns(1);
		}
		catch (std::filesystem::filesystem_error& error)
		{
			Editor::Console::PrintToConsole(Editor::MessageType::ERROR, error.what());
		}
	}

	ImGui::End();
}