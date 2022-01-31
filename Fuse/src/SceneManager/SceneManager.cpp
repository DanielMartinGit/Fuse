#include "SceneManager.h"

Fuse::SceneManager::SceneManager() { m_CurrentScene = nullptr; }
Fuse::SceneManager::~SceneManager() {}

void Fuse::SceneManager::OnSceneLoaded(Fuse::Scene& scene)
{
	m_CurrentScene = &scene;
	m_CurrentScene->OnSceneLoaded();
	m_LoadedScenes.emplace_back(m_CurrentScene);
}

void Fuse::SceneManager::OnSceneInput(double deltaTime)
{
	if (m_CurrentScene != nullptr)
		m_CurrentScene->OnSceneInput(deltaTime);
}

void Fuse::SceneManager::OnSceneUpdate(double deltaTime)
{
	if (m_CurrentScene != nullptr)
		m_CurrentScene->OnSceneUpdate(deltaTime);
}

void Fuse::SceneManager::OnSceneRendered()
{
	if (m_CurrentScene != nullptr)
		m_CurrentScene->OnRenderScene();
}

void Fuse::SceneManager::OnSceneChanged(Fuse::Scene& scene)
{
	m_CurrentScene->OnSceneUnloaded();

	m_CurrentScene = &scene;
	m_LoadedScenes.emplace_back(m_CurrentScene);
	m_CurrentScene->OnSceneLoaded();
}

void Fuse::SceneManager::OnSceneUnloaded()
{
	if (m_CurrentScene != nullptr)
		m_CurrentScene->OnSceneUnloaded();
}

void Fuse::SceneManager::OnSceneRemoved(Fuse::Scene* scene)
{
	std::vector<Fuse::Scene*>::iterator position = std::find(m_LoadedScenes.begin(), m_LoadedScenes.end(), scene);

	if (position != m_LoadedScenes.end())
	{
		m_CurrentScene->OnSceneUnloaded();

		m_LoadedScenes.erase(position);
		m_CurrentScene = nullptr;
	}
}