#include "Editor.h"

EditorUI::EditorApplication::EditorApplication()
{
	m_FPS = 0;

	m_CurrentTime = 0;
	m_FrameTime = 0;
	m_LastTime = 0;

	m_PanelManager.AddPanel("Stats", &m_Profiler);
	m_PanelManager.AddPanel("Scene View", &m_SceneViewport);
	//m_PanelManager.AddPanel("Game View", &m_GameView);
	m_PanelManager.AddPanel("Scene Hierarchy", &m_SceneHierarchy);
	m_PanelManager.AddPanel("Resources", &m_Resources);
	m_PanelManager.AddPanel("Inspector", &m_Inspector);
	m_PanelManager.AddPanel("Console", &m_Console);
	m_PanelManager.AddPanel("Asset Browser", &m_AssetBrowser);
}
EditorUI::EditorApplication::~EditorApplication() {}

void EditorUI::EditorApplication::ProcessInput(GLFWwindow* window) {}

void EditorUI::EditorApplication::SetupScene()
{
	m_Scene = Fuse::Scene("Untitled Scene");
	Fuse::SceneManager::OnSceneLoaded(m_Scene);

	m_SceneViewport.LoadResources();
	m_AssetBrowser.LoadResources();

	m_Resources.AddAllResources();
}

void EditorUI::EditorApplication::Render()
{
	ImGui::Begin("Editor", 0, ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoDocking);
	
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
		ImVec2 vWindowSize = ImGui::GetMainViewport()->Size;
		ImVec2 vPos0 = ImGui::GetMainViewport()->Pos;

		ImGui::SetWindowPos(ImVec2((float)vPos0.x, (float)vPos0.y), ImGuiCond_Always);
		ImGui::SetWindowSize(ImVec2((float)vWindowSize.x, (float)vWindowSize.y), ImGuiCond_Always);
	ImGui::PopStyleVar();

	HandlePanelDocking();
	RunLoadedScene();
	RenderActivePanels();

	ImGui::End();
}

void EditorUI::EditorApplication::HandlePanelDocking()
{
	m_DockSpaceID = ImGui::GetID("DockSpace");
	ImGui::DockSpace(m_DockSpaceID, ImVec2(0.f, 0.f), ImGuiDockNodeFlags_None | ImGuiDockNodeFlags_PassthruCentralNode);
}

void EditorUI::EditorApplication::RunLoadedScene()
{
	Fuse::Time::CalculateDeltaTime();

	Fuse::SceneManager::OnSceneInput(Fuse::Time::GetDeltaTime());
	Fuse::SceneManager::OnSceneUpdate(Fuse::Time::GetDeltaTime());
	Fuse::SceneManager::OnSceneRendered();

	m_Resources.AddAllResources();
}

void EditorUI::EditorApplication::RenderActivePanels()
{
	m_MenuBar.OnImGuiRender();
	m_PanelManager.RenderActivePanels();
}

void EditorUI::EditorApplication::CalculateFPSFrametime()
{
	m_CurrentTime = glfwGetTime();
	m_FPS++;

	if (m_CurrentTime - m_LastTime >= 1.0)
	{
		m_Profiler.SetFPS(m_FPS);

		m_FrameTime = 0.1f / m_FPS;
		m_Profiler.SetFrametime(m_FrameTime);

		m_FPS = 0;
		m_FrameTime = 0;
		m_LastTime = m_CurrentTime;
	}
}