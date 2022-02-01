#pragma once
#include "../../../../Fuse/src/ProjectManager/ProjectManager.h"
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
				ImGui::SetWindowSize(ImVec2(460, 300));

				ImGui::Text("Project Name:");
				ImGui::SameLine();
				ImGui::InputText("##name", m_ProjectName, 128);

				ImGui::Text("Project Destination:");
				ImGui::SameLine();
				ImGui::InputText("##destination", m_ProjectDestination, 128);

				ImGui::Separator();

				if(ImGui::Button("Create", ImVec2(50, 20)))
				{
					if (Fuse::ProjectManager::CreateNewProject(m_ProjectName, m_ProjectDestination))
						m_IsActive = false;
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