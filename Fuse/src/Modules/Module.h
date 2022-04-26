#pragma once
#include <string>

namespace Fuse
{
	class Module
	{
		public:
			Module(std::string name)
			{
				m_Name = name;
				m_IsEnabled = true;
			}
			~Module() {}

		public:
			virtual void Init() {}

			virtual void ProcessInput(double deltaTime) {}
			virtual void Update(double deltaTime) {}
			virtual void Render() {}

		public:
			void SetIsEnabled(bool enabled) { m_IsEnabled = enabled; }

		public:
			bool GetIsEnabled() { return m_IsEnabled; }
			std::string GetModuleName() { return m_Name; }

		private:
			std::string m_Name;
			bool m_IsEnabled;
	};
}