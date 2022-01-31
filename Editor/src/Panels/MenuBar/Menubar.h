#pragma once
#include "../../../../Fuse/Vendor/ImGui/imgui.h"

namespace Fuse
{
	class Menubar
	{
		public:
			Menubar();
			~Menubar();

		public:
			void OnImGuiRender();
	};
}