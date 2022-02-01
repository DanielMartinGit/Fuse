#pragma once
#include "../../../../Fuse/Vendor/ImGui/imgui.h"
#include "../../../../Fuse/src/ProjectManager/ProjectManager.h"
#include "../../Menus/NewProject/NewProject.h"

namespace Editor
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