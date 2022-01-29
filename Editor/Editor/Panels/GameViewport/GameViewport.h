#pragma once
#include "../../../../Fuse/Panels/BasePanel/Panel.h"

namespace Fuse
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