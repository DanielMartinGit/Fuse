#pragma once
#include "../../../../Fuse/src/Panels/BasePanel/Panel.h"
#include "../../../../Fuse/src/SceneManager/SceneManager.h"

namespace Editor
{
	class SceneViewport : public Fuse::Panel
	{
		public:
			SceneViewport();
			~SceneViewport();

		public:
			void LoadResources()
			{
				m_MoveIcon = Fuse::ResourceManager::LoadTexture("Resources/Textures/Icons/MoveButton.png");
				m_RotateIcon = Fuse::ResourceManager::LoadTexture("Resources/Textures/Icons/RotateButton.png");
				m_ScaleIcon = Fuse::ResourceManager::LoadTexture("Resources/Textures/Icons/ScaleButton.png");
			}
			void OnImGuiRender() override;

		private:
			uint32_t m_MoveIcon;
			uint32_t m_RotateIcon;
			uint32_t m_ScaleIcon;
	};
}