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
					auto& spriteRenderer = view.get<Fuse::SpriteRenderer2D>(entity);
					auto& transform = view.get<Fuse::Transform>(entity);
					
					if(spriteRenderer.GetActiveState())
						Fuse::Renderer2D::DrawSprite(transform, spriteRenderer.GetTexture());
				}
			}
	};
}