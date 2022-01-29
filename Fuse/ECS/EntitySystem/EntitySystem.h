#pragma once
#include "../../Vendor/Entt/entt.hpp"

#include "../../../Editor/Editor/Panels/Console/Console.h"
#include "../Components/Components.h"

namespace Fuse
{
	class EntitySystem
	{
		public:
			EntitySystem()
			{ 
				m_World = new entt::registry(); 
				m_EntityCount = 0;
			}
			~EntitySystem() {}

		public:
			static entt::entity& OnEntityAddedWithTransform()
			{
				auto entity = m_World->create();

				Fuse::Console::PrintToConsole(Fuse::MessageType::ACTION, "Entity Added to Scene");
				
				OnComponentAdded<Fuse::Entity>(entity);
				OnComponentAdded<Fuse::Transform>(entity);

				GetComponent<Fuse::Entity>(entity).SetEntityName("Entity " + std::to_string(m_EntityCount));
				GetComponent<Fuse::Entity>(entity).SetEntityID(m_EntityCount);

				++m_EntityCount;
				return entity;
			}

			static entt::entity& OnEmptyEntityAdded()
			{
				auto entity = m_World->create();

				Fuse::Console::PrintToConsole(Fuse::MessageType::ACTION, "Empty Entity Added to Scene");

				OnComponentAdded<Fuse::Entity>(entity);

				GetComponent<Fuse::Entity>(entity).SetEntityName("Entity " + std::to_string(m_EntityCount));
				GetComponent<Fuse::Entity>(entity).SetEntityID(m_EntityCount);

				++m_EntityCount;
				return entity;
			}

			template<class T>
			static void OnComponentAdded(entt::entity& entity)
			{
				bool hasComponent = m_World->any_of<T>(entity);

				if (!hasComponent)
				{
					m_World->emplace<T>(entity);
					Fuse::Console::PrintToConsole(Fuse::MessageType::ACTION, "Component Added");
				}
				else
				{
					Fuse::Console::PrintToConsole(Fuse::MessageType::ERROR, "Entity already contains this component");
				}
			}

			template<class T>
			static void OnComponentRemoved(entt::entity& entity)
			{
				bool hasComponent = m_World->any_of<T>(entity);

				if (hasComponent)
				{
					m_World->erase<T>(entity);
					Fuse::Console::PrintToConsole(Fuse::MessageType::ACTION, "Component Removed");
				}
				else
				{
					Fuse::Console::PrintToConsole(Fuse::MessageType::ERROR, "Entity didn't contain component");
				}
			}

			template<typename T>
			static T& GetComponent(entt::entity& entity)
			{
				bool hasComponent = m_World->any_of<T>(entity);

				if (hasComponent)
				{
					return m_World->get<T>(entity);
					Fuse::Console::PrintToConsole(Fuse::MessageType::ACTION, "Got Component from Entity");
				}
			}

			template<typename T>
			static bool HasComponent(entt::entity& entity)
			{
				return m_World->any_of<T>(entity);
			}

			static void OnEntityRemoved(entt::entity& entity)
			{
				if (m_World->valid(entity))
				{
					m_World->destroy(entity);
				}
			}

			static size_t GetEntities() { return m_World->alive(); }
			static entt::registry* GetWorld() { return m_World; }

		private:
			inline static entt::registry* m_World;

		private:
			inline static int m_EntityCount;
	};
}