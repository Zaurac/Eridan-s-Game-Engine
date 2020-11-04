#include "Camera.h"

Camera::Camera()
{
	view = glm::mat4(1.0f);
	projection = glm::mat4(1.0f);
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

	projection = glm::perspective(glm::radians(45.0f), (float)800 / (float)600, 0.1f, 100.0f);
	

	//camera param
	position = glm::vec3(0.0f, 0.0f, 3.0f);
	cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
}

Camera::~Camera()
{
}

void Camera::Update(GLFWwindow* camera)
{
	MoveCamera(camera);
	glfwGetWindowSize(camera, &width, &height);
	projection = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);
	view = glm::lookAt(position, position + cameraFront, cameraUp);
}


void Camera::MoveCamera(GLFWwindow* camera)
{
	const float cameraSpeed = 0.05f;
	if (glfwGetKey(camera, GLFW_KEY_W) == GLFW_PRESS)
	{
		position += cameraSpeed * cameraFront;
	}
	if (glfwGetKey(camera, GLFW_KEY_S) == GLFW_PRESS)
	{
		position -= cameraSpeed * cameraFront;
	}

	if (glfwGetKey(camera, GLFW_KEY_A) == GLFW_PRESS)
	{
		position -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	}

	if (glfwGetKey(camera, GLFW_KEY_D) == GLFW_PRESS)
	{
		position += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	}
}

