#include "Input.h"

Fuse::Input::Input(std::vector<int> keysToTrack, std::vector<int> mouseButtonsToTrack)
{
	m_IsEnabled = true;
	m_ScrollWheelYOffset = 0;

	for (int key : keysToTrack)
	{
		m_Keys[key] = false;
	}

	for (int mouseButton : mouseButtonsToTrack)
	{
		m_MouseButtons[mouseButton] = false;
	}

	m_Instances.emplace_back(this);
}

Fuse::Input::Input(std::vector<int> keysToTrack)
{
	m_IsEnabled = true;
	m_ScrollWheelYOffset = 0;

	for (int key : keysToTrack)
	{
		m_Keys[key] = false;
	}

	m_Instances.emplace_back(this);
}

Fuse::Input::~Input()
{
	m_Instances.erase(std::remove(m_Instances.begin(), m_Instances.end(), this), m_Instances.end());
}

void Fuse::Input::InitialiseCallbacks(GLFWwindow* window)
{
	glfwSetKeyCallback(window, Input::KeyCallback);
	glfwSetMouseButtonCallback(window, Input::MouseButtonCallback);
	glfwSetCursorPosCallback(window, Input::MousePositionCallback);
	glfwSetScrollCallback(window, Input::MouseScrollCallback);
}

bool& Fuse::Input::GetMouseButtonDown(int button)
{
	bool result = false;

	if (m_IsEnabled)
	{
		std::map<int, bool>::iterator it = m_MouseButtons.find(button);

		if (it != m_MouseButtons.end())
		{
			result = m_MouseButtons[button];
		}
	}

	return result;
}

bool& Fuse::Input::GetKeyDown(int key)
{
	bool result = false;

	if (m_IsEnabled)
	{
		std::map<int, bool>::iterator it = m_Keys.find(key);

		if (it != m_Keys.end())
		{
			result = m_Keys[key];
		}
	}
	return result;
}

void Fuse::Input::SetMouseButtonDown(int button, bool status)
{
	std::map<int, bool>::iterator it = m_MouseButtons.find(button);

	if (it != m_MouseButtons.end())
	{
		m_MouseButtons[button] = status;
	}
}

void Fuse::Input::SetKeyDown(int key, bool status)
{
	std::map<int, bool>::iterator it = m_Keys.find(key);
	
	if (it != m_Keys.end())
	{
		m_Keys[key] = status;
	}
}

void Fuse::Input::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	for (Fuse::Input* input : m_Instances)
	{
		input->SetKeyDown(key, action != GLFW_RELEASE);
	}
}

void Fuse::Input::MouseButtonCallback(GLFWwindow* window, int key, int action, int mods)
{
	for (Fuse::Input* input : m_Instances)
	{
		input->SetMouseButtonDown(key, action != GLFW_RELEASE);
	}
}

void Fuse::Input::MousePositionCallback(GLFWwindow* window, double xPos, double yPos)
{
	for (Fuse::Input* input : m_Instances)
	{
		input->SetMousePosOnScreen(glm::vec2(xPos, yPos));
	}
}

void Fuse::Input::MouseScrollCallback(GLFWwindow* window, double xOffset, double yOffset)
{
	for (Fuse::Input* input : m_Instances)
	{
		input->SetMouseScrollY(yOffset);
	}
}