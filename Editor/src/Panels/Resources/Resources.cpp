#include "Resources.h"

Editor::Resources::Resources()
{
	m_ShaderCount = 0;
	m_TextureCount = 0;
}
Editor::Resources::~Resources() {}

void Editor::Resources::AddAllResources()
{
	// Used to loop through all resources stored in the ResourceManager and add them to the list
	m_TextureCount = Fuse::ResourceManager::GetTextureCount();
	m_ShaderCount = Fuse::ResourceManager::GetShaderCount();
}

void Editor::Resources::OnImGuiRender()
{
	ImGui::Begin("Resources", &GetActiveState());

	if (ImGui::TreeNode("Textures"))
	{
		ImGui::BulletText("Textures Loaded: %i", m_TextureCount);
		ImGui::TreePop();
	}
	if (ImGui::TreeNode("Shaders"))
	{
		ImGui::BulletText("Shaders Loaded: %i", m_ShaderCount);

		ImGui::Separator();
		ImGui::Button("Reload Shaders");

		ImGui::TreePop();
	}

	ImGui::End();
}