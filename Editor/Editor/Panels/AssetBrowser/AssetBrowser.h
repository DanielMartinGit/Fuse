#pragma once
#include "../../../../Fuse/Panels/BasePanel/Panel.h"

namespace Fuse
{
	class AssetBrowser : public Fuse::Panel
	{
		public:
			AssetBrowser();
			~AssetBrowser();

		public:
			void OnImGuiRender() override;
	};
}