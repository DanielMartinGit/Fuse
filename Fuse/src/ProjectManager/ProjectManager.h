#pragma once
#include "../../Vendor/JSON/json.hpp"

#include <iostream>

namespace Fuse
{
	class ProjectManager
	{
		public:
			ProjectManager();
			~ProjectManager();

		public:
			static bool CreateNewProject(const char* name, const char* path);

		public:
			static void LoadProject(const char* path);
			static void UnloadLoadedProject();

		private:
			struct m_LoadedProject
			{
				const char* m_ProjectName = "";
				const char* m_ProjectPath = "";
				nlohmann::json m_SceneFile;
			};

		private:
			inline static m_LoadedProject m_Project;
	};
}