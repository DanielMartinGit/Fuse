#include "Menubar.h"

Editor::Menubar::Menubar() {}
Editor::Menubar::~Menubar() {}

void Editor::Menubar::OnImGuiRender()
{
	if (ImGui::BeginMenuBar())
	{
		if (ImGui::BeginMenu("File"))
		{
			ImGui::MenuItem("Open");
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

		if (Menus::NewProject::m_IsActive)
		{
			Menus::NewProject::ShowCreateProjectMenu();
		}

		ImGui::EndMenuBar();
	}
}