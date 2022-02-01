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

namespace Fuse
{
	class ShaderProgram
	{
		public:
			ShaderProgram();
			~ShaderProgram();

		public:
			void LoadShader(const char* shaderName, GLuint shaderType, const char* path);
			void CreateShader(const char* shaderName, GLuint shaderType);
			void Link();
			void Use();

			void ClearProgram();

		public:
			bool CheckShaderCompilation(GLuint shader, const char* shaderName);
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
			std::vector<uint32_t> m_Shaders;

			std::string m_VertexCode;
			std::string m_FragmentCode;

			uint32_t m_VertexShader;
			uint32_t m_ComputeShader;
			uint32_t m_FragmentShader;
			uint32_t m_ShaderProgramID;

			const char* m_VertexShaderCode;
			const char* m_FragmentShaderCode;
			const char* m_ComputeShaderCode;
	};
}