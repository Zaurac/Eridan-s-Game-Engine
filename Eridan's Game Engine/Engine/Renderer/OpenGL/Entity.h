#pragma once
#include <iostream>
#include <vector>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "ShaderLoaderOpenGL.h"
#include "Engine/Renderer/OpenGL/Camera.h"

#include <Texture2DLoaderOpenGL.h>

#define SHADER_3D_COLOR 0
#define SHADER_3D_TEXTURE 1
#define SHADER_3D_LIGHT 2
#define SHADER_3D 3
#define SHADER_2D 4


struct Vertex
{
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
	
};

class Entity
{
public:
	Entity();
	virtual ~Entity();

	ShaderLoaderOpenGL shader;
	glm::mat4 model;

	void Draw(Camera &camera);
	void SetPosition(glm::vec3 position);
	void SetRotation(float radians,glm::vec3 rotation);
	void SetColor(glm::vec3 setColor);
	void SetTexture(const char* path);

	void CreateVertex(float x, float y, float z);
	void CreateVertex(glm::vec3 position, glm::vec3 normal);
	void CreateVertex(glm::vec3 position, glm::vec2 uv);
	void CreateVertex(glm::vec3 position, glm::vec3 normal, glm::vec2 uv);
	
	virtual void Update(float deltaTime);
	void CleanUp();

	void AssignShader(int type);

	void CreateShader(const char* vertexPath, const char* fragmentPath, int type);


	bool drawable = true;

	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;

protected:
	
	void CreateEntity();
	void GenerateBufferWithoutEBO();
	void GenerateBufferWithEBO();
	
private:
	unsigned int VAO,VBO,EBO;
	int type;
	Texture2D texture;
};