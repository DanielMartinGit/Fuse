#pragma once
#include "../../../../Fuse/Panels/BasePanel/Panel.h"
#include ".../../../../../../Fuse/Vendor/Entt/entt.hpp"
#include "../SceneHierarchy/SceneHierarchy.h"

namespace Fuse
{
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
			void ShowComponents();

		private:
			bool m_DisplayComponents;
			const char* m_ComponentText[3] = { "Transform", "Sprite Renderer2D", "Box Collider2D" };
			const char* m_CurrentItem;
			ImGuiTextFilter m_Components;
	};
}