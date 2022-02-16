#pragma once
#include "../../../Fuse/src/Panels/PanelManager/PanelManager.h"
#include "../../../Fuse/src/Time/Time.h"

namespace EditorUI
{
	class EditorApplication
	{
		public:
			EditorApplication();
			~EditorApplication();

		public:
			void Render();

			void RenderActivePanels();
			void HandlePanelDocking();

			void SetupScene();
			void RunLoadedScene();

		public:
			void ProcessInput(GLFWwindow* window);
			void CalculateFPSFrametime();
			void ResetLastTime() { m_FPS = 0; m_LastTime = glfwGetTime(); }

		private:
			ImGuiID m_DockSpaceID = 0;

		private:
			Editor::Menubar m_MenuBar;

			Editor::Profiler m_Profiler;
			Editor::SceneViewport m_SceneViewport;
			Editor::GameViewport m_GameView;
			Editor::SceneHierarchy m_SceneHierarchy;
			Editor::Resources m_Resources;
			Editor::Inspector m_Inspector;
			Editor::Console m_Console;
			Editor::AssetBrowser m_AssetBrowser;

		private:
			Fuse::PanelManager m_PanelManager;
			Fuse::Scene m_Scene;

		private:
			double m_CurrentTime;
			double m_LastTime;
			double m_FrameTime;
			int m_FPS;
	};
}