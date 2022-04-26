#pragma once
#include "../../../Fuse/src/Window/BaseWindow.h"

namespace FuseHub
{
	enum class m_HubOptions { PROJECTS, INSTALLS, CREATEPROJECT, LOADPROJECT };

	class FuseHubApplication : public Fuse::Window
	{
		public:
			FuseHubApplication();
			~FuseHubApplication();

		public:
			void MainLoop();

			void Initialise() override;
			void ProcessInput() override;
			void Update(double deltaTime) override;
			void Render() override;

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