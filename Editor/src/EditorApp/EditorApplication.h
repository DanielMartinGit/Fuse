#pragma once
#include "../../../Fuse/src/Window/BaseWindow.h"
#include "../Editor/Editor.h"

namespace Editor
{
	class EditorApplication : public Fuse::Window
	{
		public:
			EditorApplication();
			~EditorApplication();

		public:
			void MainWindowLoop();

		public:
			void Initialise() override;
			void ProcessInput() override;
			void Update(double deltaTime) override;
			void Render() override;

		private:
			EditorUI::EditorApplication* m_Editor;
	};
}