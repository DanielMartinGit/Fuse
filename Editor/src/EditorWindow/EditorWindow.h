#pragma once
#include "../../../Fuse/src/Window/BaseWindow.h"
#include "../Editor/Editor.h"

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
			void Update(double deltaTime) override;
			void Render() override;

		private:
			EditorUI::EditorApplication* m_Editor;
	};
}