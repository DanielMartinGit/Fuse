#pragma once
#include "../../../../Fuse/src/Panels/BasePanel/Panel.h"

#include <filesystem>
#include <string>
#include "../Console/Console.h"

namespace Editor
{
	class AssetBrowser : public Fuse::Panel
	{
		public:
			AssetBrowser();
			~AssetBrowser();

		public:
			void OnImGuiRender() override;

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
	};
}