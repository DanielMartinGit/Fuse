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

		Editor::Console::PrintToConsole(Editor::MessageType::ACTION, "Created Project!");

		std::string projectPath = destinationPath + "/" + (std::string)projectName + "/Assets";

		m_Project.m_ProjectName = projectName;
		m_Project.m_ProjectPath = projectPath;
		m_Project.m_SceneFile = std::ofstream(projectPath + "/" + (std::string)projectName + ".scene");

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
		Utils::JsonHandler::SerialiseEntity(entity, m_Project.m_SceneFile);
	}

	std::string message = "Scene Saved with ";
	message.append(std::to_string(view.size()) + " entities");
	Editor::Console::PrintToConsole(Editor::MessageType::ACTION, message.c_str());
}

void Fuse::ProjectManager::UnloadLoadedProject()
{
	m_Project.m_ProjectName = "";
	m_Project.m_ProjectPath = "";
	m_Project.m_SceneFile.close();
}