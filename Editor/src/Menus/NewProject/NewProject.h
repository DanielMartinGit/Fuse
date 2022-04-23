#pragma once
#include "../../../../Fuse/src/ProjectManager/ProjectManager.h"
#include "../../Panels/Console/Console.h"
#include "../../../../Fuse/Vendor/ImGui/imgui_stdlib.h"
#include "../../../../Fuse/src/Utils/FileDialogs/FileDialogs.h"

namespace Menus
{
	class NewProject
	{
		public:
			NewProject() {}
			~NewProject() {}

		public:
			static void ShowCreateProjectMenu()
			{
				ImGui::Begin("New Project", &m_IsActive, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoDocking);
				ImGui::SetWindowSize(ImVec2(460, 200));

				ImGui::Text("Project Name:");
				ImGui::InputText("##name", &m_ProjectName);

				ImGui::Text("Project Destination:");
				ImGui::InputText("##destination", &m_ProjectDestination);

				ImGui::SameLine();
				if (ImGui::Button("Choose Path", ImVec2(50, 20)))
				{
					if (FuseUtils::FileDialog::SelectEmptyProjectFolder())
					{
						m_ProjectDestination = FuseUtils::FileDialog::GetProjectPath();
					}
				}

				if(ImGui::Button("Create", ImVec2(50, 20)))
				{
					if (Fuse::ProjectManager::CreateNewProject(m_ProjectName, m_ProjectDestination))
					{
						m_IsActive = false;
					}
					else
						Editor::Console::PrintToConsole(Editor::MessageType::ISSUE, "Invalid project path or name");
				}

				ImGui::End();
			}

		public:
			inline static bool m_IsActive = false;

		private:
			inline static std::string m_ProjectName;
			inline static std::string m_ProjectDestination;
	};
}