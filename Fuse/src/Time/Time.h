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
			static double GetDeltaTime() { return m_DeltaTime; }
			static double GetFrametime() { return m_FrameTime; }
			static int GetFPS() { return m_FPS; }

		public:
			static void CalculateDeltaTime()
			{
				m_CurrentFrame = glfwGetTime();
				m_DeltaTime = m_CurrentFrame - m_LastFrame;
				m_LastFrame = m_CurrentFrame;
			}

			static void CalculateFrameTimeFPS()
			{
				m_CurrentTime = glfwGetTime();
				m_FPS++;

				if (m_CurrentTime - m_LastTime >= 1.0)
				{
					m_FrameTime = 0.1f / m_FPS;

					m_FPS = 0;
					m_FrameTime = 0;
					m_LastTime = m_CurrentTime;
				}
			}

		private:
			inline static double m_CurrentTime;
			inline static double m_LastTime;
			inline static double m_FrameTime;
			inline static int m_FPS;

		private:
			inline static double m_CurrentFrame;
			inline static double m_DeltaTime;
			inline static double m_LastFrame;
	};
}