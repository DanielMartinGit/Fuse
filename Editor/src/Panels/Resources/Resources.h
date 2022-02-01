#pragma once
#include "../../../../Fuse/src/Panels/BasePanel/Panel.h"
#include "../../../../Fuse/src/ResourceManager/ResourceManager.h"

namespace Editor
{
	class Resources : public Fuse::Panel
	{
		public:
			Resources();
			~Resources();

		public:
			void OnImGuiRender() override;
			void AddAllResources();

		private:
			size_t m_TextureCount;
			size_t m_ShaderCount;
	};
}