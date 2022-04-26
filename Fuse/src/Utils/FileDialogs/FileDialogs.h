#pragma once
#include "../../../Vendor/PFD/portable-file-dialogs.h"

namespace FuseUtils
{
	class FileDialog
	{
		public:
			FileDialog() {}
			~FileDialog() {}

		public:
			static bool SelectEmptyProjectFolder()
			{
				m_ProjectPath = pfd::select_folder("Select Project Path").result();

				if (!m_ProjectPath.empty())
				{
					return true;
				}

				return false;
			}

			static bool SelectProjectFolder()
			{
				m_ProjectPath = pfd::select_folder("Select Project Folder").result();

				if (!m_ProjectPath.empty())
				{
					std::cout << "Project Folder Selected: " << m_ProjectPath << std::endl;
					return true;
				}

				return false;
			}

			// Options are multiselect (for multiple files), None, Force Overwrite
			static void OpenFile(std::string windowTitle, std::string initialPath, std::vector<std::string> filters = { "All Files", "*" }, pfd::opt option = pfd::opt::none)
			{
				auto selected = pfd::open_file(windowTitle, initialPath, filters, option).result();

				for (auto const& filename : selected)
				{
					std::cout << filename << std::endl;
				}

				m_SelectedFilePath = selected[0];
			}

			// Options are None, Force Overwrite
			static void SaveFile(std::string windowTitle, std::string initialPath, std::vector<std::string> filters = { "All Files", "*" }, pfd::opt option = pfd::opt::none)
			{
				auto savedFile = pfd::save_file(windowTitle, initialPath, filters, option).result();
				std::cout << savedFile << std::endl;
			}

		public:
			static std::string GetProjectPath() { return m_ProjectPath; }
			static std::string GetSelectedFilePath() { return m_SelectedFilePath; }

		private:
			static inline std::string m_SelectedFilePath;
			static inline std::string m_ProjectPath = "";
	};
}