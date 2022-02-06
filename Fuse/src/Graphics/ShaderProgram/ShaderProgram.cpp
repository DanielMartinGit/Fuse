#include "ShaderProgram.h"

Fuse::ShaderProgram::ShaderProgram()
{
	m_ShaderProgramID = 0;
}
Fuse::ShaderProgram::~ShaderProgram() {}

void Fuse::ShaderProgram::CreateShader(Fuse::Shader& shader)
{
	shader.SetShader(glCreateShader(shader.GetShaderType()));
	glShaderSource(shader.GetShader(), 1, &shader.m_ShaderCode, NULL);
	glCompileShader(shader.GetShader());

	if (CheckShaderCompilation(shader.GetShader()))
	{
		m_Shaders.push_back(shader);
	}
}

void Fuse::ShaderProgram::Link()
{
	m_ShaderProgramID = glCreateProgram();

	for (auto shader : m_Shaders)
	{
		glAttachShader(m_ShaderProgramID, shader.GetShader());
	}
	
	glLinkProgram(m_ShaderProgramID);
	
	if (CheckShaderLink(m_ShaderProgramID))
	{
		for (auto shader : m_Shaders)
		{
			glDeleteShader(shader.GetShader());
		}
	}
}

void Fuse::ShaderProgram::Use()
{
	glUseProgram(m_ShaderProgramID);
}

bool Fuse::ShaderProgram::CheckShaderCompilation(GLuint shader)
{
	int success;
	char infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);

		Editor::Console::PrintToConsole(Editor::MessageType::ERROR, "Error Compiling Shader");
		std::cout << infoLog << std::endl;
		return false;
	}
	else
	{
		Editor::Console::PrintToConsole(Editor::MessageType::MESSAGE, "Shader Compiled");
		return true;
	}
}

bool Fuse::ShaderProgram::CheckShaderLink(GLuint shaderProgram)
{
	int success;
	char infoLog[512];
	glGetProgramiv(shaderProgram, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		Editor::Console::PrintToConsole(Editor::MessageType::ERROR, "Shader Link Failed");
		std::cout << infoLog << std::endl;
		return false;
	}
	else
	{
		Editor::Console::PrintToConsole(Editor::MessageType::MESSAGE, "Shader Link Successful");
		return true;
	}
}

void Fuse::ShaderProgram::SetBool(const std::string& name, bool value) const
{
	glUniform1i(glGetUniformLocation(m_ShaderProgramID, name.c_str()), value);
}

void Fuse::ShaderProgram::SetInt(const std::string& name, int value) const
{
	glUniform1i(glGetUniformLocation(m_ShaderProgramID, name.c_str()), value);
}

void Fuse::ShaderProgram::SetFloat(const std::string& name, float value) const
{
	glUniform1f(glGetUniformLocation(m_ShaderProgramID, name.c_str()), value);
}

void Fuse::ShaderProgram::SetUniformMatrix4fv(const char* uniformName, GLsizei count, GLboolean transpose, const GLfloat* value)
{
	GLuint location = glGetUniformLocation(GetActiveShaderProgram(), uniformName);
	glUniformMatrix4fv(location , 1, GL_FALSE, value);
}

void Fuse::ShaderProgram::SetUniformMatrix4(const char* uniformName, const glm::mat4& matrix)
{
	GLuint location = glGetUniformLocation(GetActiveShaderProgram(), uniformName);
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
}

void Fuse::ShaderProgram::ClearProgram()
{
	m_ShaderProgramID = 0;
	m_Shaders.clear();
}