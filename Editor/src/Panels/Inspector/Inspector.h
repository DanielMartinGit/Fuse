#pragma once
#include "../../../../Fuse/src/Panels/BasePanel/Panel.h"
#include "../../../../Fuse/src/Utils/FileDialogs/FileDialogs.h"
#include "../../../../Editor/src/Panels/SceneHierarchy/SceneHierarchy.h"
#include "../../../../Fuse/Vendor/Entt/entt.hpp"

namespace Editor
{
	enum class m_ComponentTypes { None, Transform, SpriteRenderer2D, BoxCollider2D };

	class Inspector : public Fuse::Panel
	{
		public:
			Inspector();
			~Inspector();

		public:
			void OnImGuiRender() override;

		public:
			void ShowEntityComponents();
			void ShowComponentsMenu();

		public:
			void AddComponentToEntity(m_ComponentTypes component);
			void ShowComponents();

		private:
			m_ComponentTypes m_Components;
			const char* m_CurrentItem;
			bool m_DisplayComponents;
	};
}