#include "PanelManager.h"

Fuse::PanelManager::PanelManager() {}
Fuse::PanelManager::~PanelManager() {}

void Fuse::PanelManager::AddPanel(const char* name, Fuse::Panel* panel)
{
	m_Panels[name] = panel;
}

void Fuse::PanelManager::RenderActivePanels()
{
	for (auto panel : m_Panels)
	{
		if (panel.second->GetActiveState())
		{
			panel.second->OnImGuiRender();
		}
	}
}