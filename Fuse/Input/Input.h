#pragma once
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <iostream>

#include "../Vendor/GLFW/glfw3.h"
#include "../Vendor/GLM/ext/vector_float2.hpp"

namespace Fuse
{
	class Input
	{
	public:
			Input() { m_IsEnabled = true; m_ScreenPos = glm::vec2(0.0f, 0.0f); }
			Input(std::vector<int> keysToTrack);
			Input(std::vector<int> keysToTrack, std::vector<int> mouseButtonsToTrack);
			~Input();

		public:
			bool& GetKeyDown(int key);
			void SetKeyDown(int key, bool status);

			bool& GetMouseButtonDown(int button);
			void SetMouseButtonDown(int button, bool status);

			double& GetScrollWheelY() { return m_ScrollWheelYOffset; }
			void SetMouseScrollY(double yOffset) { m_ScrollWheelYOffset = yOffset; }

			void SetMousePosOnScreen(glm::vec2 screenPos) { m_ScreenPos = screenPos; }
			glm::vec2& GetMousePosFromScreen() { return m_ScreenPos; }

		public:
			bool& GetIsEnabled() { return m_IsEnabled; }
			bool& SetIsEnabled(bool enabled) { m_IsEnabled = enabled; }
				
		public:
			static void InitialiseCallbacks(GLFWwindow* window);

		private:
			std::map<int, bool> m_Keys;
			std::map<int, bool> m_MouseButtons;

			bool m_IsEnabled;
			inline static double m_ScrollWheelYOffset;

			glm::vec2 m_ScreenPos;

		private:
			static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
			static void MouseButtonCallback(GLFWwindow* window, int key, int action, int mods);
			static void MousePositionCallback(GLFWwindow* window, double xPos, double yPos);
			static void MouseScrollCallback(GLFWwindow* window, double xOffset, double yOffset);

		private:
			inline static std::vector<Input*> m_Instances;
	};
}