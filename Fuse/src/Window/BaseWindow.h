#pragma once
#include "../../../Fuse/src/Initialisation/Initialisation.h"
#include "../../../Fuse/src/Layers/InputLayer/InputLayer.h"
#include "../../../Fuse/src/Theme/ImGuiTheme.h"
#include "../Time/Time.h"

#include <string>
#include <iostream>
#include <cstdint>

namespace Fuse
{
	class Window
	{
		public:
			Window()
			{
				m_Window = nullptr;
			}
			~Window() {}

		public:
			void InitialiseWindow(uint32_t width, uint32_t height, const char* windowTitle)
			{
				m_WindowWidth = width;
				m_WindowHeight = height;
				m_WindowTitle = windowTitle;

				if (!m_Initialised)
				{
					m_InitLayer.InitialiseOpenGL();
					m_Window = m_InitLayer.InitialiseWindow(m_WindowWidth, m_WindowHeight, m_WindowTitle);

					m_InitLayer.InitialiseGLAD();

					InitialiseLayers();

					m_InitLayer.InitialiseImGui(m_Window, m_EditorTheme, m_GLSLVersion);

					m_Initialised = true;
				}
			}

			void InitialiseLayers()
			{
				m_InputLayer.InitialiseCallback(m_Window);
				m_InputLayer.OnCreate();

				m_Layers.emplace_back(m_InputLayer);
			}

			void MainLoop()
			{
				while (!glfwWindowShouldClose(m_Window))
				{
					// Input
					ProcessInput();

					// Update
					Update(Fuse::Time::GetDeltaTime());

					// Render
					Render();

					// Check events and Swap Buffers
					glfwSwapBuffers(m_Window);
					glfwPollEvents();
				}

				// Destroy the Input Layer
				m_InputLayer.OnDestroy();

				// Shutdown ImGui and destroy the GLFW window, then terminate GLFW altogether
				ImGui_ImplOpenGL3_Shutdown();
				ImGui_ImplGlfw_Shutdown();
				ImGui::DestroyContext();

				// Destroy the Window and Terminate GLFW
				glfwDestroyWindow(m_Window);
				glfwTerminate();
			}

		public:
			virtual void Initialise() = 0;
			virtual void ProcessInput() = 0;
			virtual void Update(float deltaTime) = 0;
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