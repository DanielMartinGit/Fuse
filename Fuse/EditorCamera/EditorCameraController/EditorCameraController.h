#pragma once
#include "../../Input/Input.h"
#include "../../EditorCamera/EditorCamera.h"

namespace Fuse
{
	class EditorCameraController
	{
		public:
			EditorCameraController();
			EditorCameraController(float left, float right, float bottom, float top);
			~EditorCameraController();

		public:
			void HandleInput(double deltaTime);

		public:
			Fuse::EditorCamera* GetCamera() { return m_EditorCamera; }

		private:
			std::vector<int> m_TrackedKeys;
			std::vector<int> m_TrackedMouseButtons;
			
		private:
			float m_MovementDistance;

		private:
			Fuse::EditorCamera* m_EditorCamera;
			Fuse::Input* m_Input;
	};
}