#include "ProjectManager.h"

Fuse::ProjectManager::ProjectManager() {}
Fuse::ProjectManager::~ProjectManager() {}

bool Fuse::ProjectManager::CreateNewProject(const char* projectName, const char* projectPath)
{
	if (std::filesystem::exists(projectPath))
	{
		Editor::Console::PrintToConsole(Editor::MessageType::ACTION, "Creating Project!");

		std::filesystem::create_directory((std::string)projectPath + "/" + (std::string)projectName);
		std::filesystem::create_directory((std::string)projectPath + "/" + (std::string)projectName + "/" + "Assets");
		std::filesystem::create_directory((std::string)projectPath + "/" + (std::string)projectName + "/" + "Build");
		std::filesystem::create_directory((std::string)projectPath + "/" + (std::string)projectName + "/" + "Library");
		std::filesystem::create_directory((std::string)projectPath + "/" + (std::string)projectName + "/" + "Project Settings");

		std::ofstream scene((std::string)projectPath + "\\" + (std::string)projectName + "/Assets/" + (std::string)projectName + ".scene");
		
		Editor::Console::PrintToConsole(Editor::MessageType::ACTION, "Created Project!");

		Fuse::SceneManager::OnSceneCreated(projectName);		
		return true;
	}
	else
	{
		return false;
	}
}

void Fuse::ProjectManager::LoadProject(const char* path)
{
	m_Project.m_ProjectPath = path;
}

void Fuse::ProjectManager::UnloadLoadedProject()
{

}