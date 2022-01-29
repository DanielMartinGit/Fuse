#include "Menubar.h"

Fuse::Menubar::Menubar() {}
Fuse::Menubar::~Menubar() {}

void Fuse::Menubar::OnImGuiRender()
{
	if (ImGui::BeginMenuBar())
	{
		if (ImGui::BeginMenu("File"))
		{
			ImGui::MenuItem("Open");
			ImGui::MenuItem("Save");
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
		ImGui::EndMenuBar();
	}
}