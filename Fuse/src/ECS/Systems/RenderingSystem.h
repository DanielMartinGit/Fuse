#pragma once
#include "../Components/Components.h"
#include "../../Graphics/Rendering/Renderer2D/Renderer2D.h"
#include "../EntitySystem/EntitySystem.h"

namespace Fuse
{
	class RenderingSystem
	{
		public:
			RenderingSystem() {}
			~RenderingSystem() {}

		public:
			void Render(entt::registry& world)
			{
				auto view = world.view<Fuse::Transform, Fuse::SpriteRenderer2D>();

				for (auto& entity : view)
				{
					m_SpriteRenderer = view.get<Fuse::SpriteRenderer2D>(entity);
					m_Transform = view.get<Fuse::Transform>(entity);
					
					if(m_SpriteRenderer.GetActiveState())
						Fuse::Renderer2D::DrawSprite(m_Transform, m_SpriteRenderer.GetTexture());
				}
			}

		private:
			Fuse::SpriteRenderer2D m_SpriteRenderer;
			Fuse::Transform m_Transform;
	};
}