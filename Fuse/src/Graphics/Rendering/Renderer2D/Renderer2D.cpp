#define STB_IMAGE_IMPLEMENTATION
#include "Renderer2D.h"

Fuse::Renderer2D::Renderer2D() {}
Fuse::Renderer2D::~Renderer2D() {}

void Fuse::Renderer2D::InitialiseRenderer(Fuse::EditorCamera& camera)
{
	m_EditorCamera = camera;

	m_FrameBuffer.InitialiseFramebuffer(1469, 738);
	InitialiseBuffers();
}

void Fuse::Renderer2D::InitialiseBuffers()
{
	glGenVertexArrays(1, &m_Quad.m_QuadVAO);
	glGenBuffers(1, &m_Quad.m_QuadVBO);
	glGenBuffers(1, &m_Quad.m_QuadEBO);

	glBindVertexArray(m_Quad.m_QuadVAO);
	glBindBuffer(GL_ARRAY_BUFFER, m_Quad.m_QuadVBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Quad.m_QuadEBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(m_Quad.m_Vertices), m_Quad.m_Vertices, GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(m_Quad.indices), m_Quad.indices, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// texture coord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);
}

void Fuse::Renderer2D::Bind()
{
	m_Indices = 0;
	m_Vertices = 0;
	m_DrawCalls = 0;
	m_FrameBuffer.Bind();
}

void Fuse::Renderer2D::DrawSprite(Fuse::Transform& transform, uint32_t& texture)
{
	m_Quad.m_QuadTexture = texture;

	m_Transform = glm::mat4(1.0f);

	m_Transform = glm::rotate(m_Transform, glm::radians(transform.GetRotation().x), glm::vec3(0.0f, 0.0f, 1.0f)) * 
	glm::scale(m_Transform, glm::vec3(transform.GetScale().x, transform.GetScale().y, 1.0f)) *
	glm::translate(m_Transform, glm::vec3(transform.GetTranslation().x, transform.GetTranslation().y, 1.0f));

	Fuse::ResourceManager::GetShaderProgram().Use();
	Fuse::ResourceManager::GetShaderProgram().SetUniformMatrix4fv("transform", 1, GL_FALSE, glm::value_ptr(m_Transform));

	glBindTexture(GL_TEXTURE_2D, m_Quad.m_QuadTexture);
	glBindVertexArray(m_Quad.m_QuadVAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	++m_DrawCalls;

	m_Indices += 3;
	m_Vertices += 8;
}

void Fuse::Renderer2D::Unbind()
{
	m_FrameBuffer.Unbind();
}