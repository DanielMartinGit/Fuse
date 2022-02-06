#pragma once
#include "../Graphics/ShaderProgram/ShaderProgram.h"
#include "../../Vendor/STB/stb_image.h"

namespace Fuse
{
	class ResourceManager
	{
		public:
			ResourceManager();
			~ResourceManager();

		public:
			static uint32_t& LoadTexture(const char* path);

			static void CreateShader(const char* path, GLuint shaderType);
			static void LinkShaders() { m_ShaderProgram.Link(); }

		public:
			static int GetTextureCount() { return m_TextureCount; }
			static size_t GetShaderCount() { return m_ShaderProgram.GetShadersLoaded(); }

		public:
			static Fuse::ShaderProgram& GetShaderProgram() { return m_ShaderProgram; }

		public:
			inline static Fuse::ShaderProgram m_ShaderProgram;
			inline static int m_TextureCount;

		private:
			inline static std::unordered_map<std::string, uint32_t> m_LoadedTextures;
	};
}