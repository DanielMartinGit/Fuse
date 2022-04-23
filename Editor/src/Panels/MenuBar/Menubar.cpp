#include "Menubar.h"

Editor::Menubar::Menubar() {}
Editor::Menubar::~Menubar() {}

void Editor::Menubar::OnImGuiRender()
{
	if (ImGui::BeginMenuBar())
	{
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Open Scene")) 
			{ 
				std::vector<std::string> extensions = { "Scene Files", "*.scene" };
				FuseUtils::FileDialog::OpenFile("Open Scene File", ".", extensions, pfd::opt::none);
			}
			if (ImGui::MenuItem("Save")) { Fuse::ProjectManager::SaveProject(); }

			ImGui::Separator();

			if (ImGui::MenuItem("Create New Project"))
			{
				Menus::NewProject::m_IsActive = !Menus::NewProject::m_IsActive;
			}
			if (ImGui::MenuItem("Load Project")) { Fuse::ProjectManager::LoadProject("C:/users/Danie/Desktop/Test"); }

			ImGui::Separator();

			ImGui::MenuItem("Shutdown");

			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("Edit"))
		{
			ImGui::MenuItem("Copy");
			ImGui::MenuItem("Cut");
			ImGui::MenuItem("Paste");

			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("Panels"))
		{
			ImGui::MenuItem("Scene Hierarchy");
			ImGui::MenuItem("Scene Viewport");
			ImGui::MenuItem("Game Viewport");
			ImGui::MenuItem("Profiler");

			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("Help"))
		{
			ImGui::MenuItem("About");

			ImGui::EndMenu();
		}

		if (Menus::NewProject::m_IsActive)
		{
			Menus::NewProject::ShowCreateProjectMenu();
		}

		ImGui::EndMenuBar();
	}
}