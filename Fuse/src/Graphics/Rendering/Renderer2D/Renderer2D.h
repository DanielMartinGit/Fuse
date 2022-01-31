#pragma once
#include "../../../ResourceManager/ResourceManager.h"
#include "../../../Graphics/ShaderProgram/ShaderProgram.h"
#include "../../Framebuffer/Framebuffer.h" 
#include "../../../EditorCamera/EditorCamera.h"
#include "../../../ECS/Components/Components.h"

namespace Fuse
{
	class Renderer2D
	{
		public:
			Renderer2D();
			~Renderer2D();

		public:
			static void InitialiseRenderer(Fuse::EditorCamera& camera);

		public:
			static void Bind();
			static void DrawSprite(Fuse::Transform& transform, uint32_t& texture);
			static void Unbind();

		public:
			static uint32_t GetFramebufferObject() { return m_FrameBuffer.GetFramebufferObject(); }
			static Fuse::Framebuffer& GetFramebuffer() { return m_FrameBuffer; }	

			void DeleteFramebuffer() { m_FrameBuffer.DeleteCurrentBuffer(); }

		public:
			inline static int m_DrawCalls;
			inline static int m_Vertices;
			inline static int m_Indices;

			inline static int GetDrawcalls() { return m_DrawCalls; }
			inline static int GetTotalVertices() { return m_Vertices; }
			inline static int GetTotalIndices() { return m_Indices; }

		private:
			static void InitialiseBuffers();

		private:
			struct m_QuadBase
			{
				inline static float m_Vertices[32] =
				{
					// positions          // colors           // texture coords
					 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
					 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
					-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
					-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
				};

				inline static uint32_t indices[6] =
				{
					0, 1, 3,
					1, 2, 3
				};

				inline static uint32_t m_QuadVAO;
				inline static uint32_t m_QuadVBO;
				inline static uint32_t m_QuadEBO;

				inline static uint32_t m_QuadTexture;
			};

			inline static glm::mat4 m_Transform;

		private:
			inline static m_QuadBase m_Quad;
			inline static Fuse::Framebuffer m_FrameBuffer;
			inline static Fuse::EditorCamera m_EditorCamera;
	};
}