#pragma once
#include <fstream>
#include <sstream>

#include "../../../Vendor/GLAD/glad.h"
#include "../../../../Editor/src/Panels/Console/Console.h"

namespace Fuse
{
	class Shader
	{
		public:
			Shader()
			{
				m_ShaderString = "";
				m_ShaderCode = "";
				m_Shader = 0;
				m_ShaderType = GL_VERTEX_SHADER;
			}

			Shader(const char* path, GLuint shaderType)
			{
				m_ShaderString = "";
				m_ShaderCode = "";
				m_Shader = 0;

				SetShaderType(shaderType);
				LoadShaderFile(path);
			}
			~Shader() {}

		public:
			void LoadShaderFile(const char* path)
			{
				try
				{
					std::stringstream shaderStream;

					std::ifstream shaderFile(path);
					shaderStream << shaderFile.rdbuf();

					m_ShaderString = shaderStream.str();
					SetShaderCode(m_ShaderString.c_str());

					shaderFile.close();
					Editor::Console::PrintToConsole(Editor::MessageType::ACTION, "Loaded Shader File!");
				}
				catch (std::ofstream::failure e)
				{
					Editor::Console::PrintToConsole(Editor::MessageType::ERROR, "Cannot find shader file!");
				}
			}

			const char* GetShaderCode() { return m_ShaderCode; }
			GLuint& GetShaderType() { return m_ShaderType; }
			uint32_t& GetShader() { return m_Shader; }

			void SetShaderCode(const char* shaderCode) { m_ShaderCode = shaderCode; }
			void SetShaderType(GLuint shaderType) { m_ShaderType = shaderType; }
			void SetShader(uint32_t shader) { m_Shader = shader; }
		public:
			std::string m_ShaderString;
			uint32_t m_Shader;
			GLuint m_ShaderType;
			const char* m_ShaderCode;
	};
}