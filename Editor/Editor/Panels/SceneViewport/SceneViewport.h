#pragma once
#include "../../../../Fuse/Panels/BasePanel/Panel.h"
#include "../../../../Fuse/SceneManager/SceneManager.h"

namespace Fuse
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