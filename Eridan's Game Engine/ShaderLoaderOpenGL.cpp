#include "ShaderLoaderOpenGL.h"

ShaderLoaderOpenGL::ShaderLoaderOpenGL()
{
}

ShaderLoaderOpenGL::ShaderLoaderOpenGL(const char* vertexPath, const char* fragmentPath)
{
	std::string vertexCode;
	std::string fragmentCode;
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;

	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try
	{
		vShaderFile.open(vertexPath);	
		fShaderFile.open(fragmentPath);
		std::stringstream vShaderStream, fShaderStream;
		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();

		vShaderFile.close();
		fShaderFile.close();

		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
	}
	catch(std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}

	const char *vShaderCode = vertexCode.c_str();
	const char *fShaderCode = fragmentCode.c_str();

	unsigned int vertex, fragment;
	int succes;
	char infoLog[512];

	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);

	glGetShaderiv(vertex, GL_COMPILE_STATUS, &succes);
	if (!succes)
	{
		glGetShaderInfoLog(vertex, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);

	glGetShaderiv(fragment, GL_COMPILE_STATUS, &succes);
	if (!succes)
	{
		glGetShaderInfoLog(fragment, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	glLinkProgram(ID);

	glGetProgramiv(ID, GL_LINK_STATUS, &succes);
	if (!succes)
	{
		glGetProgramInfoLog(ID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}

	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

void ShaderLoaderOpenGL::Use()
{
	glUseProgram(ID);
}

void ShaderLoaderOpenGL::setBool(const std::string& name, bool value) const
{
	glUseProgram(ID);
	glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void ShaderLoaderOpenGL::setInt(const std::string& name, int value) const
{
	glUseProgram(ID);
	glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void ShaderLoaderOpenGL::setFloat(const std::string& name, float value) const
{
	glUseProgram(ID);
	glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

void ShaderLoaderOpenGL::setUniformMatrix4(const std::string& name, glm::mat4 value)
{
	glUseProgram(ID);
	glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}

void ShaderLoaderOpenGL::setVec3(const std::string& name, glm::vec3 value)
{
	glUseProgram(ID);
	glUniform3f(glGetUniformLocation(ID, name.c_str()), value.r, value.g, value.b);
}
