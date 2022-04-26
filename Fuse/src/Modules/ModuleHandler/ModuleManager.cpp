#include "ModuleManager.h"

Fuse::ModuleManager::ModuleManager()
{
	m_Modules = std::vector<Fuse::Module*>();
}
Fuse::ModuleManager::~ModuleManager() {}

void Fuse::ModuleManager::InitModules()
{
	for (auto& currModule : m_Modules)
		if(currModule->GetIsEnabled())
			currModule->Init();
}

void Fuse::ModuleManager::AddModule(Fuse::Module* module)
{
	m_Modules.emplace_back(module);
}

void Fuse::ModuleManager::UpdateModules(double deltaTime)
{
	for (Fuse::Module* currModule : m_Modules)
		if (currModule->GetIsEnabled())
			currModule->Update(deltaTime);
}

void Fuse::ModuleManager::RenderModule()
{
	for (Fuse::Module* currModule : m_Modules)
		if (currModule->GetIsEnabled())
			currModule->Render();
}

void Fuse::ModuleManager::EnableModule(Fuse::Module* module, bool enabled)
{
	auto it = std::find(m_Modules.begin(), m_Modules.end(), module);
	
	if (it != m_Modules.end())
	{
		module->SetIsEnabled(enabled);
	}
}