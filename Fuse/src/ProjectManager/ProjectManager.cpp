#include "ProjectManager.h"

Fuse::ProjectManager::ProjectManager() {}
Fuse::ProjectManager::~ProjectManager() {}

bool Fuse::ProjectManager::CreateNewProject(std::string projectName, std::string destinationPath)
{
	if (std::filesystem::exists(destinationPath))
	{
		m_Project = m_LoadedProject();

		Editor::Console::PrintToConsole(Editor::MessageType::ACTION, "Creating Project!");

		std::filesystem::create_directory((std::string)destinationPath + "/" + (std::string)projectName);
		std::filesystem::create_directory((std::string)destinationPath + "/" + (std::string)projectName + "/" + "Assets");
		std::filesystem::create_directory((std::string)destinationPath + "/" + (std::string)projectName + "/" + "Build");
		std::filesystem::create_directory((std::string)destinationPath + "/" + (std::string)projectName + "/" + "Library");
		std::filesystem::create_directory((std::string)destinationPath + "/" + (std::string)projectName + "/" + "Project Settings");

		std::ofstream scene((std::string)destinationPath + "/" + (std::string)projectName + "/Assets/" + (std::string)projectName + ".scene");
		std::string projectPath = destinationPath + "/" + (std::string)projectName + "/Assets";

		Editor::Console::PrintToConsole(Editor::MessageType::ACTION, "Created Project!");

		m_Project.m_ProjectName = projectName;
		m_Project.m_ProjectPath = projectPath;

		Editor::AssetBrowser::LoadAssetBrowserIcons();
		Editor::AssetBrowser::SetProjectPath(m_Project.m_ProjectPath);
		Fuse::SceneManager::OnSceneCreated(projectName.c_str());		

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

void Fuse::ProjectManager::SaveProject()
{
	auto view = Fuse::EntitySystem::GetWorld()->view<Fuse::Entity>();

	for (auto entity : view)
	{
		
	}

	Editor::Console::PrintToConsole(Editor::MessageType::ACTION, "Scene Saved");
}

void Fuse::ProjectManager::UnloadLoadedProject()
{

}