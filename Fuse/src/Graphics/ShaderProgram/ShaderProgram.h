#pragma once
#include <iostream>
#include <unordered_map>

#include <vector>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <fstream>
#include <filesystem>

#include "../../../Vendor/GLAD/glad.h"
#include "../../../Vendor/GLM/gtc/type_ptr.hpp"
#include "../Shader/Shader.h"

namespace Fuse
{
	class ShaderProgram
	{
		public:
			ShaderProgram();
			~ShaderProgram();

		public:
			void CreateShader(Fuse::Shader& shader);

			void Link();
			void Use();

			void ClearProgram();

		public:
			bool CheckShaderCompilation(GLuint shader);
			bool CheckShaderLink(GLuint shaderProgram);

		public:
			void SetBool(const std::string& name, bool value) const
			{
				glUniform1i(glGetUniformLocation(m_ShaderProgramID, name.c_str()), value);
			}

			void SetInt(const std::string& name, int value) const
			{
				glUniform1i(glGetUniformLocation(m_ShaderProgramID, name.c_str()), value);
			}

			void SetFloat(const std::string& name, float value) const
			{
				glUniform1f(glGetUniformLocation(m_ShaderProgramID, name.c_str()), value);
			}

			void SetUniformMatrix4fv(const char* uniformName, GLsizei count, GLboolean transpose, const GLfloat* value)
			{
				GLuint location = glGetUniformLocation(GetActiveShaderProgram(), uniformName);
				glUniformMatrix4fv(location, 1, GL_FALSE, value);
			}

			void SetUniformMatrix4(const char* uniformName, const glm::mat4& matrix)
			{
				GLuint location = glGetUniformLocation(GetActiveShaderProgram(), uniformName);
				glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
			}

		public:
			GLuint GetActiveShaderProgram() { return m_ShaderProgramID; }
			size_t GetShadersLoaded() { return m_Shaders.size(); }

		private:
			std::vector<Fuse::Shader> m_Shaders;
			uint32_t m_ShaderProgramID;
	};
}