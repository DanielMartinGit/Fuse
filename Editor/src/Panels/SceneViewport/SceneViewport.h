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
			void OnImGuiRender() override;
	};
}