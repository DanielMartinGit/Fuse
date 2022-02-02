#pragma once
#include "../Console/Console.h"
#include "../../../../Fuse/src/Panels/BasePanel/Panel.h"
#include "../../../../Fuse/src/ResourceManager/ResourceManager.h"

#include <filesystem>
#include <string>

namespace Editor
{
	class AssetBrowser : public Fuse::Panel
	{
		public:
			AssetBrowser();
			~AssetBrowser();

		public:
			void OnImGuiRender() override;

			static void LoadResources()
			{
				m_FolderIcon = Fuse::ResourceManager::LoadTexture("Resources/Textures/Icons/FolderIcon.png");
				m_FileIcon = Fuse::ResourceManager::LoadTexture("Resources/Textures/Icons/FileIcon.png");
			}

		public:
			static void SetProjectPath(std::string projectPath)
			{ 
				m_AssetsDirectory = projectPath;
				m_CurrentDirectory = m_AssetsDirectory;
			}

		private:
			std::vector<std::filesystem::path> m_Paths;
			bool m_Refresh;

		private:
			static inline std::filesystem::path m_CurrentDirectory = "";
			inline static std::filesystem::path m_AssetsDirectory = "";
	
		private:
			bool m_isCompact = false;
			bool m_SameLineText = false;

			float m_PanelWidth = 0;
			float m_ThumbnailPadding = 13.0f;
			float m_ThumbnailSize = 60.0f;
			float m_CellSize = 0;
			int m_ColumnCount = 0;

		private:
			inline static uint32_t m_FileIcon;
			inline static uint32_t m_FolderIcon;
	};
}