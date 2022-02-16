#pragma once
#include "../../../Fuse/src/Window/BaseWindow.h"
#include "../Application/FuseHubApplication.h"

namespace FuseHub
{
	class HubWindow : Fuse::Window
	{
		public:
			HubWindow();
			~HubWindow();

		public:
			void Initialise() override;
			void ProcessInput() override;
			void Update(double deltaTime) override;
			void Render() override;

		private:
			FuseHub::FuseHubApplication* m_FuseHubApplication;
	};
}