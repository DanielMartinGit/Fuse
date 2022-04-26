#pragma once
#include "../Module.h"

#include <vector>

namespace Fuse
{
	class ModuleManager
	{
		public:
			ModuleManager();
			~ModuleManager();

		public:
			void InitModules();
			void AddModule(Fuse::Module* module);
			void UpdateModules(double deltaTime);
			void RenderModule();
			void EnableModule(Fuse::Module* module, bool enabled);

		private:
			std::vector<Fuse::Module*> m_Modules;
	};
}