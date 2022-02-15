#pragma once
#include "../../Vendor/GLFW/glfw3.h"
#include "../../Vendor/GLAD/glad.h"
#include "../../Vendor/ImGui/imgui_impl_glfw.h"
#include "../../Vendor/ImGui/imgui_impl_opengl3.h"

#include "../Theme/ImGuiTheme.h"

#include <iostream>

namespace Fuse
{
	class Init
	{
		public:
			Init() {}
			~Init() {}

		public:
			void InitialiseOpenGL()
			{
				glfwInit();
			}

			void InitialiseGLAD()
			{
				// Using GLAD, load all the OpenGL Function Pointers
				if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
				{
					// If they failed to load, tell the developer
					std::cout << "Failed to initialise GLAD" << std::endl;
				}
			}

			void InitialiseImGui(GLFWwindow* window, Fuse::Style& theme, const char* glslVersion)
			{
				// Initalise ImGui
				IMGUI_CHECKVERSION();
				ImGui::CreateContext();
				ImGui_ImplGlfw_InitForOpenGL(window, true);
				ImGui_ImplOpenGL3_Init(glslVersion);

				// Enable docking for ImGui Window
				ImGuiIO& io = ImGui::GetIO();
				io.ConfigFlags = ImGuiConfigFlags_DockingEnable;

				theme.SetStyle();
			}

			GLFWwindow* InitialiseWindow(uint32_t width, uint32_t height, const char* title)
			{
				// Create a new GLFW Window with the specified width, height and title
				GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);

				// If the window failed to initialise
				if (window == NULL)
				{
					// Tell the developer the window creation has failed and terminate GLFW
					std::cout << "Failed to create window!" << std::endl;
					glfwTerminate();
				}

				glfwMakeContextCurrent(window);
				glfwSetFramebufferSizeCallback(window, FramebufferSizeCallback);

				return window;
			}

			static void FramebufferSizeCallback(GLFWwindow* window, int width, int height)
			{
				glViewport(0, 0, width, height);
			}
	};
}