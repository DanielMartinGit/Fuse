#include "Profiler.h"
#include "../SceneHierarchy/SceneHierarchy.h"

Editor::Profiler::Profiler()
{
	m_Vendor = nullptr;
	m_Renderer = nullptr;
	m_OpenGlVersion = nullptr;

	m_FPS = 0;
	m_Frametime = 0;
	m_Drawcalls = 0;
}
Editor::Profiler::~Profiler() {}

void Editor::Profiler::OnImGuiRender()
{
	ImGui::Begin("Profiler", &GetActiveState(), ImGuiWindowFlags_NoCollapse);

	if (!statsPrinted)
	{
		PrintStatsToConsole();
	}

	if (ImGui::CollapsingHeader("SYSTEM STATS"), ImGuiTreeNodeFlags_DefaultOpen)
	{
		ImGui::TextWrapped("Vendor: %s", (char*)m_Vendor);
		ImGui::TextWrapped("Renderer: %s", (char*)m_Renderer);
		ImGui::TextWrapped("OpenGL Version: %s", (char*)m_OpenGlVersion);
	}
	if (ImGui::CollapsingHeader("ENGINE STATS"), ImGuiTreeNodeFlags_DefaultOpen)
	{
		ImGui::TextWrapped("FPS: %i", m_FPS);
		ImGui::TextWrapped("Frametime: %04.2f m/s", m_Frametime * 10000);
		ImGui::TextWrapped("Delta Time: %f", Fuse::Time::GetDeltaTime());
		ImGui::TextWrapped("Engine Version: %s", m_EngineVersion);
	}
	if (ImGui::CollapsingHeader("RENDERING STATS"), ImGuiTreeNodeFlags_DefaultOpen)
	{
		ImGui::Text("Selected EntityID: %i", Editor::SceneHierarchy::GetSelectedEntity());
		ImGui::Text("Entities: %i", Fuse::EntitySystem::GetEntities());
		ImGui::Text("Draw Calls: %d", Fuse::Renderer2D::GetDrawcalls());
		ImGui::Text("Vertices: %i", Fuse::Renderer2D::GetTotalVertices());
		ImGui::Text("Indices: %i", Fuse::Renderer2D::GetTotalIndices());
	}
	
	ImGui::End();
}

void Editor::Profiler::PrintStatsToConsole()
{
	m_Vendor = new GLubyte();
	m_Renderer = new GLubyte();
	m_OpenGlVersion = new GLubyte();

	m_Vendor = glGetString(GL_VENDOR);
	m_Renderer = glGetString(GL_RENDERER);
	m_OpenGlVersion = glGetString(GL_VERSION);

	statsPrinted = true;
}