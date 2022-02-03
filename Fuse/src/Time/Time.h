#pragma once
#include "../../Vendor/GLFW/glfw3.h"

namespace Fuse
{
	class Time
	{
		public:
			Time()
			{
				m_DeltaTime = 0.0f;
				m_LastFrame = 0.0f;
			}
			~Time() {}

		public:
			static double GetDeltaTime()
			{
				return m_DeltaTime;
			}

			static void CalculateDeltaTime()
			{
				m_CurrentFrame = glfwGetTime();
				m_DeltaTime = m_CurrentFrame - m_LastFrame;
				m_LastFrame = m_CurrentFrame;
			}

		private:
			inline static double m_CurrentFrame;
			inline static double m_DeltaTime;
			inline static double m_LastFrame;
	};
}