#include "ResourceManager.h"

Fuse::ResourceManager::ResourceManager() {}
Fuse::ResourceManager::~ResourceManager() {}

uint32_t& Fuse::ResourceManager::LoadTexture(const char* path)
{
	unsigned int textureID = 0;

	if (m_LoadedTextures.find(path) != m_LoadedTextures.end())
	{
		textureID = m_LoadedTextures[path];
	}
	else
	{
		glGenTextures(1, &textureID);
		glBindTexture(GL_TEXTURE_2D, textureID);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		int width = 0;
		int height = 0;
		int nrChannels = 0;

		unsigned char* data = stbi_load(path, &width, &height, &nrChannels, 0);

		if (data)
		{
			GLenum textureFormat = 0;

			switch (nrChannels)
			{
				case 1:
				{
					textureFormat = GL_RED;
				}
					break;
				case 3:
				{
					textureFormat = GL_RGB;
				}
					break;
				case 4:
				{
					textureFormat = GL_RGBA;
				}
					break;
			}

			glTexImage2D(GL_TEXTURE_2D, 0, textureFormat, width, height, 0, textureFormat, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);

			stbi_image_free(data);
			++m_TextureCount;
			m_LoadedTextures[path] = textureID;

			Editor::Console::PrintToConsole(Editor::MessageType::ACTION, "Texture Loaded!");
		}
	}

	return textureID;
}

void Fuse::ResourceManager::CreateShader(const char* path, GLuint shaderType)
{
	Fuse::Shader* shader = new Fuse::Shader(path, shaderType);
	m_ShaderProgram.CreateShader(*shader);
	delete shader;
}