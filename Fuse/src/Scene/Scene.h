#pragma once
#include "../Graphics/Rendering/Renderer2D/Renderer2D.h"
#include "../EditorCamera/EditorCameraController/EditorCameraController.h"
#include "../ECS/EntitySystem/EntitySystem.h"
#include "../ECS/Systems/RenderingSystem.h"

namespace Fuse
{
	class Scene
	{
		public:
			Scene() {}
			Scene(std::string name) { m_SceneName = name; }
			~Scene() {}

		public:
			void OnSceneLoaded()
			{
				Fuse::ResourceManager::GetShaderProgram().ClearProgram();

				m_CameraController = Fuse::EditorCameraController(1469, 738);

				Fuse::Renderer2D::InitialiseRenderer(*m_CameraController.GetCamera());

				Fuse::ResourceManager::CreateShader("Resources/Shaders/Vertex.vert", GL_VERTEX_SHADER);
				Fuse::ResourceManager::CreateShader("Resources/Shaders/Fragment.frag", GL_FRAGMENT_SHADER);
				Fuse::ResourceManager::LinkShaders();
			}

			void OnSceneInput(double deltaTime)
			{
				m_CameraController.HandleInput(deltaTime);
			}

			void OnSceneUpdate(double deltaTime)
			{
				
			}

			void OnRenderScene()
			{
				Fuse::Renderer2D::Bind();
				
				m_EntityRenderer.Render(*Fuse::EntitySystem::GetRegistry());

				Fuse::ResourceManager::GetShaderProgram().SetUniformMatrix4("viewProjection", m_CameraController.GetCamera()->GetProjectionViewMatrix());
				Fuse::Renderer2D::Unbind();
			}

			void OnSceneUnloaded()
			{
				m_EntitySystem.GetRegistry()->clear();
			}

		public:
			Fuse::Renderer2D& GetRenderer() { return m_Renderer; }
			Fuse::EntitySystem& GetEntitySystem() { return m_EntitySystem; }
			std::string& GetSceneName() { return m_SceneName; }

		private:
			std::string m_SceneName;

		private:
			Fuse::Renderer2D m_Renderer;
			Fuse::EditorCameraController m_CameraController;
	
		private:
			Fuse::RenderingSystem m_EntityRenderer;
			Fuse::EntitySystem m_EntitySystem;
	};
}