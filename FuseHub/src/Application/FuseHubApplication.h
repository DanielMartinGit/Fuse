#pragma once
#include "../../../Fuse/src/FileDialogs/FileDialogs.h"
#include "../../../Fuse/src/ProjectManager/ProjectManager.h"

namespace FuseHub
{
	enum class m_HubOptions { PROJECTS, INSTALLS, CREATEPROJECT, LOADPROJECT };

	class FuseHubApplication
	{
		public:
			FuseHubApplication();
			~FuseHubApplication();

		public:
			void Render();

		public:
			void OnImGuiRenderProjects();
			void OnImGuiRenderInstalls();
			void OnImGuiRenderCreateProject();
			void OnImGuiRenderLoadProject();

		private:
			ImGuiWindowFlags m_WindowFlags;

			ImGuiID m_DockSpaceID;
			m_HubOptions m_Option;
	};
}