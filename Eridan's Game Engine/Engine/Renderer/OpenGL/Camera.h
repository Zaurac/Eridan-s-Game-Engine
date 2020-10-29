#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <Dependencies\glfw\include\GLFW\glfw3.h>


class Camera
{
public:
	Camera();
	~Camera();

	

	void Update(GLFWwindow* camera);
	//Matrix
	glm::mat4 getViewMatrix() { return view; };
	glm::mat4 getProjectionMatrix() { return projection; }
	glm::vec3 getPosition() {return position;};


	void MoveCamera(GLFWwindow* camera);

	glm::mat4 view;
	glm::mat4 projection;

	Camera *camera;

	//camera param
	glm::vec3 position;
	glm::vec3 cameraFront;
	glm::vec3 cameraUp;

private:
	
};