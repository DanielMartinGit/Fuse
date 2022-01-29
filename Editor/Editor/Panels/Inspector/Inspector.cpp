#include "Inspector.h"

Fuse::Inspector::Inspector()
{
	m_CurrentItem = m_ComponentText[0];
	m_DisplayComponents = false;
}
Fuse::Inspector::~Inspector() {}

void Fuse::Inspector::OnImGuiRender()
{
	ImGui::Begin("Inspector", &GetActiveState());

	ShowEntityComponents();
	ShowComponentsMenu();
	
	ImGui::End();
}

void Fuse::Inspector::ShowEntityComponents()
{
	if (Fuse::SceneHierarchy::GetSelectedEntity() != nullptr)
	{
		ShowComponents();

		if (ImGui::Button("Add Component", ImVec2(ImGui::GetWindowSize().x, 25)))
		{
			m_DisplayComponents = true;
		}
	}
}

void Fuse::Inspector::ShowComponentsMenu()
{
	if (m_DisplayComponents)
	{
		if (ImGui::BeginCombo("##Components", m_CurrentItem))
		{
			m_CurrentItem = "";

			for (int component = 0; component < IM_ARRAYSIZE(m_ComponentText); ++component)
			{
				bool isSelected = (m_CurrentItem == m_ComponentText[component]);

				if (ImGui::Selectable(m_ComponentText[component], isSelected))
					m_CurrentItem = m_ComponentText[component];

				if (isSelected)
					ImGui::SetItemDefaultFocus();
			}

			if (m_CurrentItem == "Transform")
			{
				Fuse::EntitySystem::OnComponentAdded<Fuse::Transform>(*Fuse::SceneHierarchy::GetSelectedEntity());
				m_DisplayComponents = false;
			}
			else if (m_CurrentItem == "Sprite Renderer2D")
			{
				Fuse::EntitySystem::OnComponentAdded<Fuse::SpriteRenderer2D>(*Fuse::SceneHierarchy::GetSelectedEntity());
				m_DisplayComponents = false;
			}
			else if (m_CurrentItem == "Box Collider2D")
			{
				Fuse::EntitySystem::OnComponentAdded<Fuse::BoxCollider2D>(*Fuse::SceneHierarchy::GetSelectedEntity());
				m_DisplayComponents = false;
			}

			ImGui::EndCombo();
		}
	}
}

void Fuse::Inspector::ShowComponents()
{
	if (ImGui::TreeNodeEx("Entity"))
	{
		auto entityComponent = Fuse::EntitySystem::GetComponent<Fuse::Entity>(*Fuse::SceneHierarchy::GetSelectedEntity());

		std::string entityNameText = "Name: ";
		std::string entityID = "ID: ";
		std::string entityTag = "Tag: ";

		entityNameText.append(entityComponent.GetEntityName().c_str());
		entityID.append(std::to_string(entityComponent.GetEntityID()));
		entityTag.append(entityComponent.GetEntityTag().c_str());

		ImGui::Text(entityNameText.c_str());
		ImGui::Text(entityTag.c_str());
		ImGui::Text(entityID.c_str());

		ImGui::TreePop();
	}

	if (Fuse::EntitySystem::HasComponent<Fuse::Transform>(*Fuse::SceneHierarchy::GetSelectedEntity()))
	{
		auto& transformComponent = Fuse::EntitySystem::GetComponent<Fuse::Transform>(*Fuse::SceneHierarchy::GetSelectedEntity());
		
		float translation[2] { transformComponent.GetTranslation().x, transformComponent.GetTranslation().y };
		float scale[2] { transformComponent.GetScale().x, transformComponent.GetScale().y };
		float rotation[2]{ transformComponent.GetRotation().x, transformComponent.GetRotation().y };

		if (ImGui::TreeNode("Transform"))
		{
			ImGui::Text("Translation");
			ImGui::SameLine();
			ImGui::DragFloat2("##Translation", translation);

			ImGui::Text("Scale");
			ImGui::SameLine();
			ImGui::DragFloat2("##Scale", scale);

			ImGui::Text("Rotation");
			ImGui::SameLine();
			ImGui::DragFloat("##Rotation", rotation);

			ImGui::TreePop();
		}
	}

	if (Fuse::EntitySystem::HasComponent<Fuse::SpriteRenderer2D>(*Fuse::SceneHierarchy::GetSelectedEntity()))
	{
		auto& spriteComponent = Fuse::EntitySystem::GetComponent<Fuse::SpriteRenderer2D>(*Fuse::SceneHierarchy::GetSelectedEntity());

		if (ImGui::TreeNode("Sprite Renderer2D"))
		{
			if (ImGui::Button("X", ImVec2(25, 25)))
			{
				Fuse::EntitySystem::OnComponentRemoved<Fuse::SpriteRenderer2D>(*Fuse::SceneHierarchy::GetSelectedEntity());
			}

			ImGui::Checkbox("Active", &spriteComponent.GetActiveState());
			ImGui::ImageButton((ImTextureID)spriteComponent.GetTexture(), ImVec2(25, 25));

			ImGui::TreePop();
		}
	}

	if (Fuse::EntitySystem::HasComponent<Fuse::BoxCollider2D>(*Fuse::SceneHierarchy::GetSelectedEntity()))
	{
		auto& boxColliderComponent = Fuse::EntitySystem::GetComponent<Fuse::BoxCollider2D>(*Fuse::SceneHierarchy::GetSelectedEntity());

		if (ImGui::TreeNode("Box Collider2D"))
		{
			if (ImGui::Button("X", ImVec2(25, 25)))
			{
				Fuse::EntitySystem::OnComponentRemoved<Fuse::BoxCollider2D>(*Fuse::SceneHierarchy::GetSelectedEntity());
			}

			ImGui::Checkbox("Active", &boxColliderComponent.GetActiveState());

			float collisionBounds[2] = { boxColliderComponent.GetColliderBounds().x, boxColliderComponent.GetColliderBounds().y };
			ImGui::DragFloat2("Collision Bounds", collisionBounds);

			ImGui::TreePop();
		}
	}
}