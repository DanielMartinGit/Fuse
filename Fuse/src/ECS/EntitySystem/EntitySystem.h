#pragma once
#include "../../../Vendor/Entt/entt.hpp"
#include "../Components/Components.h"

namespace Fuse
{
	class EntitySystem
	{
		public:
			EntitySystem()
			{ 
				m_Registry = new entt::registry();
				m_EntityCount = 0;
			}
			~EntitySystem() {}

		public:
			static entt::entity& OnEntityAddedWithTransform()
			{
				auto entity = m_Registry->create();

				Editor::Console::PrintToConsole(Editor::MessageType::ACTION, "Entity Added to Scene");
				
				OnComponentAdded<Fuse::Entity>(entity);
				OnComponentAdded<Fuse::Transform>(entity);

				GetComponent<Fuse::Entity>(entity).SetEntityName("Entity " + std::to_string(m_EntityCount));
				GetComponent<Fuse::Entity>(entity).SetEntityID(uint32_t(entity));

				++m_EntityCount;
				return entity;
			}

			static entt::entity& OnEntityAddedWithTransformAndSprite()
			{
				auto entity = m_Registry->create();

				Editor::Console::PrintToConsole(Editor::MessageType::ACTION, "Entity Added to Scene");

				OnComponentAdded<Fuse::Entity>(entity);
				OnComponentAdded<Fuse::Transform>(entity);
				OnComponentAdded<Fuse::SpriteRenderer2D>(entity);

				GetComponent<Fuse::Entity>(entity).SetEntityName("Entity " + std::to_string(m_EntityCount));
				GetComponent<Fuse::Entity>(entity).SetEntityID(uint32_t(entity));

				++m_EntityCount;
				return entity;
			}

			static entt::entity& OnEmptyEntityAdded()
			{
				auto entity = m_Registry->create();

				Editor::Console::PrintToConsole(Editor::MessageType::ACTION, "Empty Entity Added to Scene");

				OnComponentAdded<Fuse::Entity>(entity);

				GetComponent<Fuse::Entity>(entity).SetEntityName("Entity " + std::to_string(m_EntityCount));
				GetComponent<Fuse::Entity>(entity).SetEntityID(m_EntityCount);

				++m_EntityCount;
				return entity;
			}

			template<typename T>
			static void OnComponentAdded(entt::entity& entity)
			{
				bool hasComponent = m_Registry->any_of<T>(entity);

				if (!hasComponent)
				{
					m_Registry->emplace<T>(entity);
					Editor::Console::PrintToConsole(Editor::MessageType::ACTION, "Component Added");
				}
				else
				{
					Editor::Console::PrintToConsole(Editor::MessageType::ISSUE, "Entity already contains this component");
				}
			}

			template<typename T>
			static void OnComponentRemoved(entt::entity& entity)
			{
				bool hasComponent = m_Registry->any_of<T>(entity);

				if (hasComponent)
				{
					m_Registry->erase<T>(entity);
					Editor::Console::PrintToConsole(Editor::MessageType::ACTION, "Component Removed");
				}
				else
				{
					Editor::Console::PrintToConsole(Editor::MessageType::ISSUE, "Entity didn't contain component");
				}
			}

			template<typename T>
			static T& GetComponent(entt::entity& entity)
			{
				bool hasComponent = m_Registry->any_of<T>(entity);

				if (hasComponent)
				{
					return m_Registry->get<T>(entity);
					Editor::Console::PrintToConsole(Editor::MessageType::ACTION, "Got Component from Entity");
				}
			}

			template<typename T>
			static bool HasComponent(entt::entity& entity)
			{
				return m_Registry->any_of<T>(entity);
			}

			static void OnEntityRemoved(entt::entity& entity)
			{
				if (m_Registry->valid(entity))
				{
					m_Registry->destroy(entity);
				}
			}

			static size_t GetEntities() { return m_Registry->alive(); }
			static entt::registry* GetRegistry() { return m_Registry; }

		private:
			inline static entt::registry* m_Registry;

		private:
			inline static int m_EntityCount;
	};
}