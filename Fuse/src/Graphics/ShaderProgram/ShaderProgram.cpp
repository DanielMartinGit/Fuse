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

		Editor::Console::PrintToConsole(Editor::MessageType::ISSUE, "Error Compiling Shader");
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
		Editor::Console::PrintToConsole(Editor::MessageType::ISSUE, "Shader Link Failed");
		std::cout << infoLog << std::endl;
		return false;
	}
	else
	{
		Editor::Console::PrintToConsole(Editor::MessageType::MESSAGE, "Shader Link Successful");
		return true;
	}
}

void Fuse::ShaderProgram::ClearProgram()
{
	m_ShaderProgramID = 0;
	m_Shaders.clear();
}