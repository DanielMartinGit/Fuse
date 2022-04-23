#pragma once
#include "../../../Editor/src/Panels/Console/Console.h"
#include "../../../Editor/src/Panels/AssetBrowser/AssetBrowser.h"
#include "../SceneManager/SceneManager.h"
#include "../JSON/JsonHandler.h"

#include <fstream>

namespace Fuse
{
	class ProjectManager
	{
		public:
			ProjectManager();
			~ProjectManager();

		public:
			static bool CreateNewProject(std::string& name, std::string& path);

		public:
			static void LoadProject(const char* path);
			static void UnloadLoadedProject();
			static void SaveProject();

		private:
			static void SaveScene();

		private:
			struct m_LoadedProject
			{
				std::string m_ProjectName = "";
				std::string m_ProjectPath = "";

				std::ofstream m_ProjectFile;
				std::ofstream m_SceneFile;

				nlohmann::json m_SceneData;
			};

		public:
			static m_LoadedProject& GetLoadedProject() { return m_Project; }

		private:
			inline static m_LoadedProject m_Project;
	};
}