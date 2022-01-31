#pragma once
#include "../../../Vendor/GLM/glm.hpp"
#include "../../../Vendor/GLM/gtx/matrix_decompose.hpp"
#include "../../../ResourceManager/ResourceManager.h"

namespace Fuse
{
	class Entity
	{
		public:
			Entity()
			{
				m_Active = true;
			}
			~Entity() {}

		public:
			void SetEntityName(std::string entityName) { m_EntityName = entityName; }
			void SetEntityTag(std::string entityTag) { m_EntityTag = entityTag; }
			void SetEntityID(uint32_t entityID) { m_EntityID = entityID; }

		public:
			std::string GetEntityName() { return m_EntityName; }
			std::string GetEntityTag() { return m_EntityTag; }
			uint32_t GetEntityID() { return m_EntityID; }
	
		public:
			bool m_Active;
			std::string m_EntityName = "Test Name";
			std::string m_EntityTag = "Entity";
			uint32_t m_EntityID = 0;
	};


	// TODO - Rewrite entire component (not working as intended)
	class Transform
	{
		public:
			Transform()
			{
				m_Scale = glm::vec3(1.0f, 1.0f, 1.0f);
				m_Rotation = glm::vec2(0.0f, 0.0f);
				m_Translation = glm::vec2(0.0f, 0.0f);
			}
			~Transform() {}

		public:
			glm::vec2& GetTranslation() { return m_Translation; }
			glm::vec2& GetRotation() { return m_Rotation; }
			glm::vec2& GetScale() { return m_Scale; }

		public:
			glm::vec2 m_Translation;
			glm::vec2 m_Scale;
			glm::vec2 m_Rotation;
	};

	class SpriteRenderer2D
	{
		public:
			SpriteRenderer2D()
			{
				m_Texture = 0;
				SetTexture("Resources/Textures/Texture.png");
			}
			~SpriteRenderer2D() {}

		public:
			uint32_t& GetTexture() { return m_Texture; }
			bool GetIsVisible() { return m_IsVisible; }
			bool& GetActiveState() { return m_Active; }

			void SetTexture(uint32_t texture) { m_Texture = texture; }
			void SetTexture(const char* path) { m_Texture = Fuse::ResourceManager::LoadTexture(path); }
			void SetIsVisble(bool visible) { m_IsVisible = visible; }

		private:
			bool m_Active;
			uint32_t m_Texture;
			bool m_IsVisible;
	};

	class BoxCollider2D
	{
		public:
			BoxCollider2D()
			{
				m_Active = true;
				m_ColliderBounds = glm::vec2(0, 0);
			}
			~BoxCollider2D() {}

		public:
			bool GetColliderActive() { return m_Active; }
			glm::vec2 const GetColliderBounds() { return m_ColliderBounds; }
			bool& GetActiveState() { return m_Active; }

			void SetColliderBounds(glm::vec2 colliderBounds) { m_ColliderBounds = colliderBounds; }
			void SetActive(bool active) { m_Active = active; }

		private:
			bool m_Active;
			glm::vec2 m_ColliderBounds;
	};
}