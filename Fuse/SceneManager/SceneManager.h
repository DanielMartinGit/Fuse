#pragma once
#include <unordered_map>
#include "../Scene/Scene.h"

namespace Fuse
{
	class SceneManager
	{
		public:
			SceneManager();
			~SceneManager();

		public:
			static void OnSceneLoaded(Fuse::Scene& scene);

			static void OnSceneInput(double deltaTime);
			static void OnSceneUpdate(double deltaTime);
			static void OnSceneRendered();
			static void OnSceneChanged(Fuse::Scene& scene);
			static void OnSceneUnloaded();

			static void OnSceneRemoved(Fuse::Scene* scene);
			
		public:
			static uint32_t GetSceneFBO() { return m_CurrentScene->GetRenderer().GetFramebufferObject(); }
			static Fuse::EntitySystem& GetEntitySystem() { return m_CurrentScene->GetEntitySystem(); }

		private:
			inline static Fuse::Scene* m_CurrentScene;
			inline static std::vector<Fuse::Scene*> m_LoadedScenes;
	};
}