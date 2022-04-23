#include "ProjectManager.h"

Fuse::ProjectManager::ProjectManager() {}
Fuse::ProjectManager::~ProjectManager() {}

bool Fuse::ProjectManager::CreateNewProject(std::string& projectName, std::string& destinationPath)
{
	if (std::filesystem::exists(destinationPath))
	{
		m_Project = m_LoadedProject();

		Editor::Console::PrintToConsole(Editor::MessageType::ACTION, "Creating Project!");

		std::filesystem::create_directory(destinationPath + "/" + projectName);
		std::filesystem::create_directory(destinationPath + "/" + projectName + "/" + "Assets");
		std::filesystem::create_directory(destinationPath + "/" + projectName + "/" + "Build");
		std::filesystem::create_directory(destinationPath + "/" + projectName + "/" + "Library");
		std::filesystem::create_directory(destinationPath + "/" + projectName + "/" + "Project Settings");

		m_Project.m_ProjectFile = std::ofstream(destinationPath + "/" + projectName + "/" + "Project Settings/" + projectName + ".fuse");

		Editor::Console::PrintToConsole(Editor::MessageType::ACTION, "Created Project!");

		std::string projectPath = destinationPath + "/" + projectName + "/Assets";
		m_Project.m_SceneFile = std::ofstream(projectPath + "/" + projectName + ".scene");

		m_Project.m_ProjectName = projectName;
		m_Project.m_ProjectPath = projectPath;

		Editor::AssetBrowser::SetProjectPath(m_Project.m_ProjectPath);

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
	if (m_Project.m_SceneFile.is_open())
	{
		SaveScene();
	}
	else
	{
		m_Project.m_SceneFile.open(m_Project.m_ProjectPath + "/" + (std::string)m_Project.m_ProjectName + ".scene");
		SaveScene();
	}
}

void Fuse::ProjectManager::UnloadLoadedProject()
{
	m_Project.m_ProjectName = "";
	m_Project.m_ProjectPath = "";
	m_Project.m_SceneFile.close();
}

void Fuse::ProjectManager::SaveScene()
{
	auto view = Fuse::EntitySystem::GetWorld()->view<Fuse::Entity>();

	for (auto entity : view)
	{
		Utils::JsonHandler::SerialiseEntity(entity, m_Project.m_SceneFile);
	}

	std::string message = "Scene Saved with ";

	message.append(std::to_string(view.size()) + " entities");
	Editor::Console::PrintToConsole(Editor::MessageType::ACTION, message.c_str());

	m_Project.m_SceneFile.close();
}