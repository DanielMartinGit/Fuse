#pragma once
#include "../../../Fuse/src/Initialisation/Initialisation.h"
#include "../../../Fuse/src/Layers/InputLayer/InputLayer.h"
#include "../Time/Time.h"

#include <cstdint>

namespace Fuse
{
	class Window
	{
		public:
			Window();
			~Window();

		public:
			void InitialiseWindow(uint32_t width, uint32_t height, const char* windowTitle);
			void InitialiseLayers();
			void MainLoop();

		public:
			void BeginFrame();
			void EndFrame();

		public:
			virtual void Initialise() = 0;
			virtual void ProcessInput() = 0;
			virtual void Update(double deltaTime) = 0;
			virtual void Render() = 0;

		protected:
			uint32_t m_WindowWidth = 1920;
			uint32_t m_WindowHeight = 1080;
			const char* m_WindowTitle = "Fuse Editor";
			const char* m_GLSLVersion = "#version 460";

		protected:
			Fuse::Style m_EditorTheme;
			Fuse::InputLayer m_InputLayer;
			Fuse::Init m_InitLayer;

			std::vector<Fuse::Layer> m_Layers;

			bool m_Initialised = false;

		protected:
			GLFWwindow* m_Window;
	};
}