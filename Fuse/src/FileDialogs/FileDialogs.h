#pragma once
#include "../../Vendor/PFD/portable-file-dialogs.h"

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

		public:
			static std::string GetProjectPath() { return m_ProjectPath; }

		private:
			static inline std::string m_ProjectPath = "";
	};
}