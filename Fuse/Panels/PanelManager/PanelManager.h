#pragma once

#include "../BasePanel/Panel.h"

#include "../../../Editor/Editor/Panels/AssetBrowser/AssetBrowser.h"
#include "../../../Editor/Editor/Panels/Console/Console.h"
#include "../../../Editor/Editor/Panels/GameViewport/GameViewport.h"
#include "../../../Editor/Editor/Panels/Inspector/Inspector.h"
#include "../../../Editor/Editor/Panels/MenuBar/Menubar.h"
#include "../../../Editor/Editor/Panels/Profiler/Profiler.h"
#include "../../../Editor/Editor/Panels/Resources/Resources.h"
#include "../../../Editor/Editor/Panels/SceneHierarchy/SceneHierarchy.h"
#include "../../../Editor/Editor/Panels/SceneViewport/SceneViewport.h"

#include <unordered_map>

namespace Fuse
{
	class PanelManager
	{
		public:
			PanelManager();
			~PanelManager();

		public:
			void RenderActivePanels();

		public:
			void AddPanel(const char* name, Fuse::Panel* panel);

		public:
			static Fuse::Panel* GetPanel(const char* name)
			{
				auto pairFound = m_Panels.find(name);

				if (pairFound != m_Panels.end())
					return pairFound->second;
				else
					return nullptr;
			}

		private:
			inline static std::unordered_map<std::string, Fuse::Panel*> m_Panels;
	};
}