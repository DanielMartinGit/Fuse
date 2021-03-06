#pragma once
#include "../../../../Fuse/src/ProjectManager/ProjectManager.h"
#include "../../Panels/Console/Console.h"
#include "../../../../Fuse/Vendor/ImGui/imgui.h"

namespace Menus
{
	class NewProject
	{
		public:
			NewProject()
			{
				
			}
			~NewProject() {}

		public:
			static void ShowCreateProjectMenu()
			{
				ImGui::Begin("New Project", &m_IsActive, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoDocking);
				ImGui::SetWindowSize(ImVec2(460, 200));

				ImGui::Text("Project Name:");
				ImGui::InputText("##name", m_ProjectName, 128);

				ImGui::Text("Project Destination:");
				ImGui::InputText("##destination", m_ProjectDestination, 128);

				ImGui::SameLine();
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
			inline static char m_ProjectName[128] = "";
			inline static char m_ProjectDestination[128] = "";
	};
}