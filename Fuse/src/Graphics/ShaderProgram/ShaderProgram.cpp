#include "ShaderProgram.h"

Fuse::ShaderProgram::ShaderProgram()
{
	m_FragmentShader = 0;
	m_VertexShader = 0;
	m_ComputeShader = 0;
	m_ShaderProgramID = 0;

	m_VertexShaderCode = "";
	m_FragmentShaderCode = "";
	m_ComputeShaderCode = "";
}
Fuse::ShaderProgram::~ShaderProgram() {}

void Fuse::ShaderProgram::LoadShader(const char* shaderName, GLuint shaderType, const char* shaderPath)
{
	std::ifstream shaderFile;

	try
	{
		std::stringstream shaderStream;

		shaderFile.open(shaderPath);
		shaderStream << shaderFile.rdbuf();
		
		if (shaderType == GL_VERTEX_SHADER)
		{
			m_VertexCode = shaderStream.str();
			m_VertexShaderCode = m_VertexCode.c_str();

			shaderFile.close();
			CreateShader(shaderName, shaderType);
		}
		else if (shaderType == GL_FRAGMENT_SHADER)
		{
			m_FragmentCode = shaderStream.str();
			m_FragmentShaderCode = m_FragmentCode.c_str();

			shaderFile.close();
			CreateShader(shaderName, shaderType);
		}
		else
		{
			std::string name(shaderName);
			std::string message = "Shader type: " + name + " Shader unsupported by Shader Program";
			Editor::Console::PrintToConsole(Editor::MessageType::ERROR, message.c_str());
		}
	}
	catch (std::ofstream::failure e)
	{
		std::cout << "ERROR: SHADER FILE NOT SUCCESSFULLY READ" << std::endl;
	}
}

void Fuse::ShaderProgram::CreateShader(const char* shaderName, GLuint shaderType)
{
	switch (shaderType)
	{
		case GL_VERTEX_SHADER:
		{
			m_VertexShader = glCreateShader(GL_VERTEX_SHADER);
			glShaderSource(m_VertexShader, 1, &m_VertexShaderCode, NULL);
			glCompileShader(m_VertexShader);

			if (CheckShaderCompilation(m_VertexShader, shaderName))
			{
				m_Shaders.emplace_back(m_VertexShader);
			}
		}
			break;	
		case GL_FRAGMENT_SHADER:
		{
			m_FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
			glShaderSource(m_FragmentShader, 1, &m_FragmentShaderCode, NULL);
			glCompileShader(m_FragmentShader);

			if (CheckShaderCompilation(m_FragmentShader, shaderName))
			{
				m_Shaders.emplace_back(m_FragmentShader);
			}
		}
			break;
		case GL_COMPUTE_SHADER:
		{
			m_ComputeShader = glCreateShader(GL_COMPUTE_SHADER);
			glShaderSource(m_ComputeShader, 1, &m_ComputeShaderCode, NULL);
			glCompileShader(m_ComputeShader);

			if (CheckShaderCompilation(m_ComputeShader, shaderName))
			{
				m_Shaders.emplace_back(m_ComputeShader);
			}
		}
			break;
	}
}

void Fuse::ShaderProgram::Link()
{
	m_ShaderProgramID = glCreateProgram();

	for (auto shader : m_Shaders)
	{
		glAttachShader(m_ShaderProgramID, shader);
	}
	
	glLinkProgram(m_ShaderProgramID);
	
	if (CheckShaderLink(m_ShaderProgramID))
	{
		for (auto shader : m_Shaders)
		{
			glDeleteShader(shader);
		}
	}
}

void Fuse::ShaderProgram::Use()
{
	glUseProgram(m_ShaderProgramID);
}

bool Fuse::ShaderProgram::CheckShaderCompilation(GLuint shader, const char* shaderName)
{
	int success;
	char infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);

		std::string message = shaderName;
		message.append(infoLog);

		Editor::Console::PrintToConsole(Editor::MessageType::ERROR, message.c_str());
		return false;
	}
	else
	{
		std::string message = "Shader Compilation Successful: ";
		message.append(shaderName);

		Editor::Console::PrintToConsole(Editor::MessageType::MESSAGE, message.c_str());
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
	m_FragmentShader = 0;
	m_VertexShader = 0;
	m_ComputeShader = 0;
	m_ShaderProgramID = 0;

	m_VertexShaderCode = "";
	m_FragmentShaderCode = "";
	m_ComputeShaderCode = "";

	m_Shaders.clear();
}