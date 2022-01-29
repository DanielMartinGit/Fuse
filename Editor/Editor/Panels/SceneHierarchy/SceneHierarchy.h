#pragma once
#include "../../../../Fuse/Panels/BasePanel/Panel.h"
#include "../../../../Fuse/SceneManager/SceneManager.h"
#include "../../../../Fuse/Vendor/Entt/entt.hpp"

namespace Fuse
{
	class SceneHierarchy : public Fuse::Panel
	{
		public:
			SceneHierarchy();
			~SceneHierarchy();

		public:
			void OnImGuiRender() override;

		public:
			static entt::entity* GetSelectedEntity() { return m_SelectedEntity; }

		private:
			inline static entt::entity* m_SelectedEntity;

		private:
			int m_EntityCount;

			int m_SelectableBools[100000];
			std::vector<entt::entity> m_Entities;
			Fuse::EntitySystem* m_EntitySystem;
	};
}