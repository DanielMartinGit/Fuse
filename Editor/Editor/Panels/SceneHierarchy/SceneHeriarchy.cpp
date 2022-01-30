#include "SceneHierarchy.h"

Fuse::SceneHierarchy::SceneHierarchy()
{
	m_EntitySystem = &Fuse::SceneManager::GetEntitySystem();
	m_EntityCount = 0;

	for (int i = 0; i < 100000; ++i)
	{
		m_SelectableBools[i] = false;
	}

	m_ShowEntityOptions = false;
}

Fuse::SceneHierarchy::~SceneHierarchy() {}

void Fuse::SceneHierarchy::OnImGuiRender()
{
	ImGui::Begin("Scene Hierarchy", &GetActiveState());

	if (ImGui::Button("+", ImVec2(25, 20)))
	{
		m_ShowEntityOptions = true;
	}

	if(m_ShowEntityOptions)
		ShowEntityOptions();

	ImGui::Separator();

	if (Fuse::SceneManager::GetEntitySystem().GetEntities() > 0)
	{
		for (auto& entity : m_Entities)
		{
			auto& entityComponent = m_EntitySystem->GetComponent<Fuse::Entity>(entity);
			
			if (ImGui::Selectable(entityComponent.GetEntityName().c_str(), m_SelectableBools[entityComponent.GetEntityID()]))
			{
				m_SelectableBools[entityComponent.GetEntityID()] = true;
				m_SelectedEntity = &entity;
			}

			if (ImGui::IsWindowHovered() && ImGui::IsMouseClicked(0))
			{
				m_SelectableBools[entityComponent.GetEntityID()] = false;
				m_SelectedEntity = nullptr;
			}
		}
	}

	if (ImGui::IsWindowHovered() && ImGui::IsMouseClicked(0))
	{
		m_ShowEntityOptions = false;
	}

	ImGui::End();
}

void Fuse::SceneHierarchy::ShowEntityOptions()
{
	if (ImGui::BeginCombo("##Options", ""))
	{
		if (ImGui::Selectable("Empty Entity"))
			CreateEntity(m_EntityOptions::EmptyEntity);

		if (ImGui::Selectable("Entity"))
			CreateEntity(m_EntityOptions::Entity);

		if (ImGui::Selectable("Sprite"))
			CreateEntity(m_EntityOptions::Sprite);

		ImGui::EndCombo();
	}
}

void Fuse::SceneHierarchy::CreateEntity(m_EntityOptions options)
{
	switch (options)
	{
		case m_EntityOptions::EmptyEntity:
		{
			auto entity = Fuse::EntitySystem::OnEmptyEntityAdded();
			m_Entities.emplace_back(entity);
			m_ShowEntityOptions = false;
		}
			break;
		case m_EntityOptions::Entity:
		{
			auto entity = Fuse::EntitySystem::OnEntityAddedWithTransform();
			m_Entities.emplace_back(entity);
			m_ShowEntityOptions = false;
		}
			break;
		case m_EntityOptions::Sprite:
		{
			auto entity = Fuse::EntitySystem::OnEntityAddedWithTransformAndSprite();
			m_Entities.emplace_back(entity);
			m_ShowEntityOptions = false;
		}
			break;
	}
}