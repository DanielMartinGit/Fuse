#include "SceneHierarchy.h"

Editor::SceneHierarchy::SceneHierarchy()
{
	m_EntitySystem = &Fuse::SceneManager::GetEntitySystem();
	m_EntityCount = 0;

	for (int i = 0; i < 100000; ++i)
	{
		m_SelectableBools[i] = false;
	}

	m_ShowEntityOptions = false;
}
Editor::SceneHierarchy::~SceneHierarchy() {}

void Editor::SceneHierarchy::OnImGuiRender()
{
	ImGui::Begin("Scene Hierarchy", &GetActiveState());

	if (ImGui::Button("+", ImVec2(25, 20)))
	{
		m_ShowEntityOptions = true;
	}

	ImGui::SameLine(ImGui::GetWindowWidth() - 190);
	ImGui::InputText("##Search", m_SearchText, 255);

	if (m_ShowEntityOptions)
		ShowEntityOptions();

	ImGui::Separator();

	if (ImGui::TreeNode(Fuse::SceneManager::GetLoadedScene().GetSceneName().c_str()))
	{
		if (Fuse::SceneManager::GetEntitySystem().GetEntities() > 0)
		{
			for (auto& entity : m_Entities)
			{
				auto& entityComponent = m_EntitySystem->GetComponent<Fuse::Entity>(entity);

				if (ImGui::Selectable(entityComponent.GetEntityName().c_str(), m_SelectableBools[entityComponent.GetEntityID()]) && m_SelectedEntity == nullptr)
				{
					m_SelectableBools[entityComponent.GetEntityID()] = true;
					m_SelectedEntity = &entity;

					ImGui::Separator();
				}

				if (ImGui::IsWindowHovered() && ImGui::IsMouseClicked(0) || m_ShowEntityOptions)
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

		ImGui::TreePop();
	}

	ImGui::End();
}

void Editor::SceneHierarchy::ShowEntityOptions()
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

void Editor::SceneHierarchy::CreateEntity(m_EntityOptions options)
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