#include "SceneHierarchy.h"

Fuse::SceneHierarchy::SceneHierarchy()
{
	m_EntitySystem = &Fuse::SceneManager::GetEntitySystem();
	m_EntityCount = 0;

	for (int i = 0; i < 100000; ++i)
	{
		m_SelectableBools[i] = false;
	}
}

Fuse::SceneHierarchy::~SceneHierarchy() {}

void Fuse::SceneHierarchy::OnImGuiRender()
{
	ImGui::Begin("Scene Hierarchy", &GetActiveState());

	if (ImGui::Button("+", ImVec2(25, 20)))
	{
		auto entity = m_EntitySystem->OnEmptyEntityAdded();
		m_Entities.emplace_back(entity);
	}

	ImGui::Separator();

	if (Fuse::SceneManager::GetEntitySystem().GetEntities() > 0)
	{
		for (auto& entity : m_Entities)
		{
			auto entityComponent = m_EntitySystem->GetComponent<Fuse::Entity>(entity);
			
			if (ImGui::Selectable(entityComponent.GetEntityName().c_str(), m_SelectableBools[entityComponent.GetEntityID()]))
			{
				m_SelectableBools[entityComponent.GetEntityID()] = true;
				m_SelectedEntity = &m_Entities[entityComponent.GetEntityID()];
			}

			if (ImGui::IsWindowHovered() && ImGui::IsMouseClicked(0))
			{
				m_SelectableBools[entityComponent.GetEntityID()] = false;
				m_SelectedEntity = nullptr;
			}
		}
	}

	ImGui::End();
}