#include "Framebuffer.h"

Fuse::Framebuffer::Framebuffer()
{ 
	m_Framebuffer = 0; 
	m_FBO = 0;

	m_CurrentWidth = 0;
	m_CurrentHeight = 0;
}
Fuse::Framebuffer::~Framebuffer() {}

void Fuse::Framebuffer::InitialiseFramebuffer(const uint32_t width, const uint32_t height)
{
	m_CurrentWidth = width;
	m_CurrentHeight = height;

	glGenFramebuffers(1, &m_FBO);
	glBindFramebuffer(GL_FRAMEBUFFER, m_FBO);

	glGenTextures(1, &m_Framebuffer);
	glBindTexture(GL_TEXTURE_2D, m_Framebuffer);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_CurrentWidth, m_CurrentHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glBindTexture(GL_TEXTURE_2D, 0);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_Framebuffer, 0);

	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
	{
		std::cout << "ERROR::FRAMEBUFFER::FRAMEBUFFER_NOT_COMPLETE" << std::endl;
	}
}

void Fuse::Framebuffer::Bind()
{
	glBindFramebuffer(GL_FRAMEBUFFER, m_FBO);
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Fuse::Framebuffer::Unbind()
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Fuse::Framebuffer::DeleteCurrentBuffer()
{
	glDeleteFramebuffers(1, &m_FBO);
	glDeleteTextures(1, &m_Framebuffer);
}

void Fuse::Framebuffer::Resize(uint32_t width, uint32_t height)
{
	if (width != 0 && height != 0)
	{
		if(m_CurrentWidth != width || m_CurrentHeight != height)
		{ 
			m_CurrentWidth = width;
			m_CurrentHeight = height;

			DeleteCurrentBuffer();
			InitialiseFramebuffer(width, height);
		}
	}
}