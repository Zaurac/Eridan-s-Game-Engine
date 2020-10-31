#include "Entity.h"

Entity::Entity() : model(glm::mat4(1.0f)) , EBO(0), VAO(0), VBO(0), type(0)
{

}

Entity::~Entity()
{
}

void Entity::AssignShader(int type)
{
	if (type == SHADER_3D_COLOR)
	{
		
	}
}


void Entity::CreateShader(const char* vertexPath, const char* fragmentPath, int type)
{
	shader = ShaderLoaderOpenGL(vertexPath,fragmentPath);
	this->type = type;
}

void Entity::CreateEntity()
{
	if (vertices.size() != NULL)
	{
		if (indices.size() != NULL)
		{
			std::cout << "Create Buffer with EBO" << std::endl;
			GenerateBufferWithEBO();
		}
		else
		{
			std::cout << "Create Buffer without EBO" << std::endl;
			GenerateBufferWithoutEBO();
		}
	}
}

void Entity::Draw(Camera &camera)
{
	shader.Use();

	

	if (texture.texture != NULL)
	{
		glBindTexture(GL_TEXTURE_2D, texture.texture);
	}
	else
	{
		texture = Texture2DLoaderOpenGL::LoadTexture("Asset/Textures/empty.jpg");
		glBindTexture(GL_TEXTURE_2D, texture.texture);
	}


	if (type == SHADER_3D_COLOR)
	{	
		shader.setUniformMatrix4("model", model);
		shader.setUniformMatrix4("view", camera.getViewMatrix());
		shader.setUniformMatrix4("projection", camera.getProjectionMatrix());
	}

	if (EBO != NULL)
	{
		
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, (GLsizei)this->indices.size(), GL_UNSIGNED_INT, 0);
	}
	else
	{
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, (GLsizei)this->vertices.size());
	}
}

void Entity::SetPosition(glm::vec3 position)
{
	this->model = glm::translate(this->model, position);
}

void Entity::SetRotation(float radians,glm::vec3 rotation)
{
	this->model	 = glm::rotate(this->model, glm::radians(radians), rotation);
}

void Entity::CreateVertex(float x, float y, float z)
{
	Vertex vertex;
	vertex.Position.x = x;
	vertex.Position.y = y;
	vertex.Position.z = z;

	vertex.Normal = glm::vec3(0,0,0);

	vertices.push_back(vertex);
}

void Entity::CreateVertex(glm::vec3 position, glm::vec3 normal)
{
	Vertex vertex;
	vertex.Position = position;
	vertex.Normal = normal;

	vertices.push_back(vertex);
}

void Entity::CreateVertex(glm::vec3 position, glm::vec2 uv)
{
	Vertex vertex;
	vertex.Position = position;
	vertex.Normal = glm::vec3(0, 0, 0);
	vertex.TexCoords = uv;

	vertices.push_back(vertex);
}

void Entity::CreateVertex(glm::vec3 position, glm::vec3 normal, glm::vec2 uv)
{
	Vertex vertex;
	vertex.Position = position;
	vertex.Normal = normal;
	vertex.TexCoords = uv;

	vertices.push_back(vertex);
}
	

void Entity::Update(float deltaTime)
{
}

void Entity::SetColor(glm::vec3 setColor)
{
	if (type == SHADER_3D_COLOR)
	{
		shader.Use();
		shader.setVec3("ourColor", setColor);
	}
}

void Entity::SetTexture(const char* path)
{
	
	Texture2D texture = Texture2DLoaderOpenGL::LoadTexture(path);
}

void Entity::SetScale(glm::vec3 scale)
{
	model = glm::scale(model, scale);
}

void Entity::GenerateBufferWithoutEBO()
{
	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);

	//VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, this->vertices.size() * sizeof(Vertex), &this->vertices.front(), GL_STATIC_DRAW);

	//VAO
	glBindVertexArray(VAO);

	//Position
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
	glEnableVertexAttribArray(0);

	//Normal
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Vertex::Normal));
	glEnableVertexAttribArray(1);

	//TexCoord
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Vertex::TexCoords));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0);
}

void Entity::GenerateBufferWithEBO()
{
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glGenVertexArrays(1, &VAO);

	//VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, this->vertices.size() * sizeof(Vertex), &this->vertices.front(), GL_STATIC_DRAW);

	//VAO
	glBindVertexArray(VAO);

	//Position
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
	glEnableVertexAttribArray(0);

	//Normal
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Vertex::Normal));
	glEnableVertexAttribArray(1);

	//TexCoord
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Vertex::TexCoords));
	glEnableVertexAttribArray(2);

	//EBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->indices.size() * sizeof(unsigned int), &this->indices.front(), GL_STATIC_DRAW);

	glBindVertexArray(0);

}

void Entity::CleanUp()
{
	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1,&VAO);
}