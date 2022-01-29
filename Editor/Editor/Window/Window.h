#pragma once

#include "../../../Editor/Editor/EditorWindow/Editor.h"
#include "../../../Fuse/Layers/InputLayer/InputLayer.h"

#include "../../../Fuse/Vendor/ImGui/imgui.h"
#include "../../../Fuse/Vendor/ImGui/imgui_impl_glfw.h"
#include "../../../Fuse/Vendor/ImGui/imgui_impl_opengl3.h"

#include <string>
#include <iostream>

namespace Fuse
{
	class Window
	{
		public:
			Window();
			Window(Fuse::Editor& editor)
			{
				m_Window = nullptr;
				m_Editor = &editor;
			}
			~Window();

		public:
			void Initialise();
			void InitialiseOpenGL();
			void InitialiseGLAD();
			void InitialiseWindow();
			void InitialiseLayers();
			void MainWindowLoop();
			void ProcessInput();

		public:
			void Render();

		public:
			void InitialiseImGui();

		public:
			static void FramebufferSizeCallback(GLFWwindow* window, int width, int height);

		public:
			void SetEditor(Fuse::Editor& editor) { m_Editor = &editor; }

		private:
			uint32_t m_WindowWidth = 1920;
			uint32_t m_WindowHeight = 1080;
			const char* m_WindowTitle = "Fuse";
			const char* m_GLSLVersion = "#version 460";

		private:
			Fuse::InputLayer m_InputLayer;
			Fuse::Editor* m_Editor;

		private:
			GLFWwindow* m_Window;

		private:
			std::vector<Fuse::Layer> m_Layers;
	};
}