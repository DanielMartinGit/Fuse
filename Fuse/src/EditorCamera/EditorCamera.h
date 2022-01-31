#pragma once
#include "../../Vendor/GLM/glm.hpp"
#include "../../Vendor/GLM/ext/matrix_clip_space.hpp"
#include "../../Vendor/GLM/ext/matrix_transform.hpp"

namespace Fuse
{
	class EditorCamera
	{
		public:
			EditorCamera() 
			{
				m_MovementSpeed = 0;
				m_Position = glm::vec3(0.0f, 0.0f, 0.0f);
				m_Rotation = 0.0f;

				m_ProjectionMatrix = glm::mat4(1.0f);
				m_ProjectionViewMatrix = glm::mat4(1.0f);
				m_Transform = glm::mat4(1.0f);
				m_ViewMatrix = glm::mat4(1.0f);
			}
			EditorCamera(float width, float height)
			{
				m_ProjectionMatrix = glm::ortho(-width / 2.0f, width / 2.0f, -height / 2.0f, height / 2.0f, 1.0f, -1.0f);
				m_ViewMatrix = glm::mat4(1.0f);
				m_Transform = glm::mat4(1.0f);

				m_Rotation = 0.0f;
				m_MovementSpeed = 0.01f;
				m_Position = glm::vec3(0.0f, 0.0f, 0.0f);

				m_ProjectionViewMatrix = m_ProjectionMatrix * m_ViewMatrix;
			}
			~EditorCamera() {}

		public:
			const glm::vec3& GetPosition() const { return m_Position; }
			void SetPosition(const glm::vec3& position) { m_Position = position; RecalculateViewMatrix(); }

			float GetRotation() const { return m_Rotation; }
			void SetRotation(float rotation) { m_Rotation = rotation; RecalculateViewMatrix(); }

		public:
			const glm::mat4 GetProjectionMatrix() const { return m_ProjectionMatrix; }
			const glm::mat4 GetViewMatrix() const { return m_ViewMatrix; }
			const glm::mat4 GetProjectionViewMatrix() const { return m_ProjectionViewMatrix; }

		private:
			void RecalculateViewMatrix()
			{
				m_Transform = glm::translate(glm::mat4(1.0f), m_Position) *
				 glm::rotate(glm::mat4(1.0f), glm::radians(m_Rotation), glm::vec3(0, 0, 1));

				m_ViewMatrix = glm::inverse(m_Transform);
				m_ProjectionViewMatrix = m_ProjectionMatrix * m_ViewMatrix;
			}

		private:
			glm::mat4 m_Transform;
			glm::mat4 m_ProjectionMatrix;
			glm::mat4 m_ViewMatrix;
			glm::mat4 m_ProjectionViewMatrix;

		private:
			glm::vec3 m_Position;
			float m_MovementSpeed; 
			float m_Rotation;

			float m_Width = 1920.0f;
			float m_Height = 1080.0f;
	};
}