#pragma once
#include "../../../../Fuse/src/Panels/BasePanel/Panel.h"

namespace Editor
{
	class GameViewport : public Fuse::Panel
	{
		public:
			GameViewport();
			~GameViewport();

		public:
			void OnImGuiRender() override;
	};
}