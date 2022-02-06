#include "SceneViewport.h"

Editor::SceneViewport::SceneViewport() {}
Editor::SceneViewport::~SceneViewport() {}

void Editor::SceneViewport::OnImGuiRender()
{
	ImGui::Begin("Scene View", &GetActiveState(), ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoTitleBar);

	ImGui::Begin("##Controls", &GetActiveState(), ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoResize);
	ImGui::SetWindowSize(ImVec2(132, 47));
	
	if (ImGui::ImageButton((ImTextureID)m_MoveIcon, ImVec2(25, 25)))
	{ 
		m_ToolType = ImGuizmo::OPERATION::TRANSLATE;
		Editor::Console::PrintToConsole(Editor::MessageType::ACTION, "Editor tool changed to Translate");
	}
	ImGui::SameLine();
	if(ImGui::ImageButton((ImTextureID)m_RotateIcon, ImVec2(25, 25)))
	{ 
		m_ToolType = ImGuizmo::OPERATION::ROTATE;
		Editor::Console::PrintToConsole(Editor::MessageType::ACTION, "Editor tool changed to Rotate");
	}
	ImGui::SameLine();
	if(ImGui::ImageButton((ImTextureID)m_ScaleIcon, ImVec2(25, 25)))
	{ 
		m_ToolType = ImGuizmo::OPERATION::SCALE;
		Editor::Console::PrintToConsole(Editor::MessageType::ACTION, "Editor tool changed to Scale");
	}

	ImGui::End();

	// Render ImGui Texture here with FBO
	ImVec2 vWindowSize = ImGui::GetWindowSize();
	ImGui::Image((ImTextureID)Fuse::SceneManager::GetSceneFBO(), vWindowSize);

	ImGui::End();
}

void Editor::SceneViewport::UseTool()
{
	switch (m_ToolType)
	{
		case ImGuizmo::OPERATION::TRANSLATE:
		{
			auto& transform = Fuse::EntitySystem::GetComponent<Fuse::Transform>(*Editor::SceneHierarchy::GetSelectedEntity());
			auto& transformComponent = Fuse::EntitySystem::GetComponent<Fuse::Transform>(*Editor::SceneHierarchy::GetSelectedEntity()).GetTransform();
			
			float* translation[3]{ &transform.GetTranslation().x, &transform.GetTranslation().y, &transform.GetTranslation().z };
			float* scale[2]{ &transform.GetScale().x, &transform.GetScale().y };
			float* rotation[1]{ &transform.GetRotation() };
		}
	}
}