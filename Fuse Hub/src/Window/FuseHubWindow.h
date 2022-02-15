#pragma once
#include "../../../Fuse/src/Window/BaseWindow.h"

namespace FuseHub
{
	class FuseHubWindow : public Fuse::Window
	{
		public:
			FuseHubWindow() { m_DockSpaceID = 0; }
			~FuseHubWindow() {}

		public:
			void Initialise() override
			{
				InitialiseWindow(1000, 550, "Fuse Hub");
				MainLoop();
			}

			void ProcessInput() override
			{
				if (glfwGetKey(m_Window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
				{
					glfwSetWindowShouldClose(m_Window, true);
				}
			}

			void Update(float deltaTime) override
			{

			}

			void Render() override
			{
				// Create a new frame for ImGui
				ImGui_ImplOpenGL3_NewFrame();
				ImGui_ImplGlfw_NewFrame();
				ImGui::NewFrame();

				// Render the Hub
				ImGui::Begin("Hub", 0, ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoDocking);
				
				ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
					ImVec2 vWindowSize = ImGui::GetMainViewport()->Size;
					ImVec2 vPos0 = ImGui::GetMainViewport()->Pos;

					ImGui::SetWindowPos(ImVec2((float)vPos0.x, (float)vPos0.y), ImGuiCond_Always);
					ImGui::SetWindowSize(ImVec2((float)vWindowSize.x, (float)vWindowSize.y), ImGuiCond_Always);
				ImGui::PopStyleVar();

				m_DockSpaceID = ImGui::GetID("MainDockSpace");
				ImGui::DockSpace(m_DockSpaceID, ImVec2(0.f, 0.f), ImGuiDockNodeFlags_None | ImGuiDockNodeFlags_PassthruCentralNode);

					ImGui::Begin("##Toolbar", NULL, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize);

					ImGui::Button("Projects", ImVec2(150, 50));
					ImGui::Button("Installs", ImVec2(150, 50));

					ImGui::End();

					ImGui::Begin("##Projects", NULL, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize);

					ImGui::Text("Projects");
					ImGui::SameLine(ImGui::GetWindowSize().x - 155);
					ImGui::Button("Create new Project", ImVec2(150, 25));
					ImGui::Separator();

					ImGui::End();

				ImGui::End();

				// Render ImGui
				ImGui::Render();
				ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
			}

		private:
			ImGuiID m_DockSpaceID;
	};
}