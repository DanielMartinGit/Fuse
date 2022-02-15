#pragma once

#include "../EditorWindow/Editor.h"
#include "../../../Fuse/src/Window/BaseWindow.h"

namespace EditorWindow
{
	class EditorWindow : public Fuse::Window
	{
		public:
			EditorWindow();
			~EditorWindow();

		public:
			void Initialise() override;
			void ProcessInput() override;
			void Update(float deltaTime) override;
			void Render() override;

		private:
			EditorUI::EditorWindow* m_Editor;
	};
}