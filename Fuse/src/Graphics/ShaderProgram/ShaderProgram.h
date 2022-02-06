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
#include "../../../../Editor/src/Panels/Console/Console.h"
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
			void SetBool(const std::string& name, bool value) const;
			void SetInt(const std::string& name, int value) const;
			void SetFloat(const std::string& name, float value) const;
			void SetUniformMatrix4fv(const char* uniformName, GLsizei count, GLboolean transpose, const GLfloat* value);
			void SetUniformMatrix4(const char* uniformName, const glm::mat4& matrix);

		public:
			GLuint GetActiveShaderProgram() { return m_ShaderProgramID; }
			size_t GetShadersLoaded() { return m_Shaders.size(); }

		private:
			std::vector<Fuse::Shader> m_Shaders;

			uint32_t m_ShaderProgramID;
	};
}