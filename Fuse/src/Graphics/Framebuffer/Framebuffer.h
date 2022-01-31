#pragma once
#include "../../../Vendor/GLAD/glad.h"

#include <cstdint>
#include <iostream>

namespace Fuse
{
	class Framebuffer
	{
		public:
			Framebuffer();
			~Framebuffer();

		public:
			void InitialiseFramebuffer(const uint32_t width, const uint32_t height);
			void Bind();
			void Unbind();
			void DeleteCurrentBuffer();

		public:
			void Resize(uint32_t width, uint32_t height);

		public:
			uint32_t GetFramebufferObject() { return m_Framebuffer; }
		
		private:
			uint32_t m_CurrentWidth;
			uint32_t m_CurrentHeight;

			uint32_t m_FBO;
			uint32_t m_Framebuffer;
	};
}