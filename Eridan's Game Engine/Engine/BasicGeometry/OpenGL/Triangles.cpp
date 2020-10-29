#include "Triangles.h"

EG::Triangles::Triangles() : VAO(0), VBO(0)
{

}

EG::Triangles::~Triangles()
{

}

void EG::Triangles::CreateTriangles(glm::vec3 position)
{

	Vertex vertex1;
	vertex1.x = 0.0f;
	vertex1.y = -0.99f;
	vertex1.z = 0.0f;

	Vertex vertex2;
	vertex2.x = 0.9f;
	vertex2.y = -0.99f;
	vertex2.z = 0.0f;

	Vertex vertex3;
	vertex3.x = 0.45f;
	vertex3.y = 0.0f;
	vertex3.z = 0.0f;

	m_verticesArray.push_back(vertex1);
	m_verticesArray.push_back(vertex2);
	m_verticesArray.push_back(vertex3);

	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, m_verticesArray.size() * sizeof(Vertex), &m_verticesArray.front(), GL_STATIC_DRAW);

	glBindVertexArray(VAO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

}

void EG::Triangles::Draw()
{
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, (GLsizei)m_verticesArray.size());
}
