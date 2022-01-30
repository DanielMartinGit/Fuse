#pragma once
#include "../../../../Fuse/Panels/BasePanel/Panel.h"
#include "../../../../Fuse/SceneManager/SceneManager.h"
#include "../../../../Fuse/Vendor/Entt/entt.hpp"

namespace Fuse
{
	enum class m_EntityOptions { EmptyEntity, Entity, Sprite };

	class SceneHierarchy : public Fuse::Panel
	{
		public:
			SceneHierarchy();
			~SceneHierarchy();

		public:
			void OnImGuiRender() override;
			void ShowEntityOptions();
			void CreateEntity(m_EntityOptions entityTypes);

		public:
			static entt::entity* GetSelectedEntity() { return m_SelectedEntity; }

		private:
			inline static entt::entity* m_SelectedEntity;

		private:
			m_EntityOptions m_EntityTypes;

			bool m_ShowEntityOptions;
			int m_EntityCount;

			int m_SelectableBools[100000];
			std::vector<entt::entity> m_Entities;
			Fuse::EntitySystem* m_EntitySystem;
	};
}