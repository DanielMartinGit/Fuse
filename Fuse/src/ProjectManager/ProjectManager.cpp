#include "ProjectManager.h"
#include "../../../Editor/src/Panels/Console/Console.h"

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

		Editor::Console::PrintToConsole(Editor::MessageType::ACTION, "Created Project!");
		
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