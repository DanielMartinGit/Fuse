#pragma once

#define GLFW_INCLUDE_NONE

#include "../../../../Fuse/src/Panels/BasePanel/Panel.h"
#include "../../../../Fuse/src/Time/Time.h"
#include "../../../../Fuse/src/Graphics/Rendering/Renderer2D/Renderer2D.h"
#include "../../../../Fuse/src/ECS/EntitySystem/EntitySystem.h"

#include <iostream>

namespace Editor
{
	class Profiler : public Fuse::Panel
	{
		public:
			Profiler();
			~Profiler();

		public:
			void OnImGuiRender() override;
			void PrintStatsToConsole();

		public:
			void SetFPS(int fps) { m_FPS = fps; }
			void SetFrametime(double frameTime) { m_Frametime = frameTime; }
			void SetDrawcalls(int drawCalls) { m_Drawcalls = drawCalls; }
		
		private:
			bool statsPrinted = false;

			const char* m_EngineVersion = "0.0.1";
			const GLubyte* m_Vendor;
			const GLubyte* m_Renderer;
			const GLubyte* m_OpenGlVersion;

			int m_FPS;
			int m_Drawcalls;
			double m_Frametime;
	};
}