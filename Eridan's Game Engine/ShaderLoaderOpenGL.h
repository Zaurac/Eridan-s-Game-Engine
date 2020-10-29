#pragma once
#include "Include.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class ShaderLoaderOpenGL
{
public:
	unsigned int ID;

	ShaderLoaderOpenGL();
	ShaderLoaderOpenGL(const char *vertexPath, const char* fragmentPath);
	void Use();

	void setBool(const std::string &name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
	void setUniformMatrix4(const std::string &name, glm::mat4 value);
	void setVec3(const std::string &name, glm::vec3 value);
};

