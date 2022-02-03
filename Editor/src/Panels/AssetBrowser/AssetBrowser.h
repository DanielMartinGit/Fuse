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
				m_RefreshButton = Fuse::ResourceManager::LoadTexture("Resources/Textures/Icons/RotateButton.png");
				m_BackButton = Fuse::ResourceManager::LoadTexture("Resources/Textures/Icons/BackButton.png");
			}

		public:
			static void SetProjectPath(std::string projectPath)
			{ 
				m_AssetsDirectory = projectPath;
				m_CurrentDirectory = m_AssetsDirectory;
			}

		private:
			inline static std::vector<std::filesystem::directory_entry> m_DirectoryEntries;
			inline static bool m_Refresh;

		private:
			static inline std::filesystem::path m_CurrentDirectory = "";
			inline static std::filesystem::path m_AssetsDirectory = "";
	
		private:
			inline static bool m_isCompact = false;
			inline static bool m_SameLineText = false;

			inline static float m_PanelWidth = 0;
			inline static float m_ThumbnailPadding = 13.0f;
			inline static float m_ThumbnailSize = 60.0f;
			inline static float m_CellSize = 0;
			inline static int m_ColumnCount = 0;

		private:
			inline static uint32_t m_FileIcon;
			inline static uint32_t m_FolderIcon;
			inline static uint32_t m_RefreshButton;
			inline static uint32_t m_BackButton;
	};
}