#include "Include.h"
#include <GLFW/glfw3.h>


#include <iostream>
#include "ShaderLoaderOpenGL.h"

#include "Engine/Imgui/imguiCustom.h"
#include "Texture2DLoaderOpenGL.h"

//GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Engine/BasicGeometry/OpenGL/Triangles.h"
#include "Engine/BasicGeometry/OpenGL/Square.h"
#include "Engine/BasicGeometry/OpenGL/Box.h"
#include "Engine/Renderer/OpenGL/Light.h"

#include "Engine/Renderer/OpenGL/Camera.h"
#include "Engine/Renderer/OpenGL/Renderer.h"


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

// lighting
glm::vec3 lightPos(1.2f, 1.0f, 2.0f);

static void glfw_error_callback(int error, const char* description)
{
	fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

int main()
{

	glfwSetErrorCallback(glfw_error_callback);
	if (!glfwInit())
	{
		std::cout << "ERROR::INIT::GLFW /n";
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);
	

	GLFWwindow *windows = glfwCreateWindow(800,600, "Game Engine 3D", NULL, NULL);
	if (!windows)
	{
		std::cout << "ERROR:CREATE::WINDOW /n";
	}
	glfwMakeContextCurrent(windows);

	

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD /n";
		return -1;
		exit(EXIT_FAILURE);
	}

	imguiCustom::Imgui_Init(windows);

	Square square;
	square.CreateQuad();
	square.CreateShader("Shader/basic3D.vert", "Shader/basic3D.frag", SHADER_3D_COLOR);
	square.shader.setVec3("ourColor", glm::vec3(1.0f,1.0f,1.0f));
	square.SetRotation(-89.f,glm::vec3(1.0f, 0.f, 0.f));
	square.SetPosition(glm::vec3(0,0,-0.5f));
	square.SetTexture("Asset/Textures/wall.jpg");

	Box box;
	box.CreateBox();
	box.SetPosition(glm::vec3(0.0f, 0.0f, 0.0f));
	box.SetColor(glm::vec3(0.8f, 0.3f, 1.0f));

	Box box2;
	box2.CreateBox();
	box2.SetPosition(glm::vec3(2.0f, 5.0f, -15.0f));
	box2.SetColor(glm::vec3(0.5f,1.0f,1.0f));

	Light light1;
	light1.CreateBox();
	light1.SetPosition(lightPos);
	light1.SetColor(glm::vec3(1.0f,0.5f,1.0f));

	Camera camera = Camera();
	Renderer renderer(windows, camera);
	
	box2.shader.setVec3("lightColor", glm::vec3(1.0f,1.0f,1.0f));
	box2.shader.setVec3("lightPos", lightPos);
	box.shader.setVec3("lightColor", glm::vec3(1.0f,1.0f,1.0f));
	box.shader.setVec3("lightPos", lightPos);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_MULTISAMPLE);
	
	glfwSwapInterval(1);

	float deltaTime = 0.0f;
	float lastFrame = 0.0f;

	while (!glfwWindowShouldClose(windows))
	{
		glfwSetFramebufferSizeCallback(windows, framebuffer_size_callback);
		processInput(windows);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

		box.shader.setVec3("viewPos", camera.getPosition());
		box2.shader.setVec3("viewPos", camera.getPosition());
		box.SetRotation((float)0.01f * 50.f,glm::vec3(0.0f, 1.0f,	0.0f));

		//DELTA TIME
		float currentFrame = (float)glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		

		//DRAW
		renderer.AddViewport(square);
		renderer.AddViewport(box);
		renderer.AddViewport(box2);
		renderer.AddViewport(light1);

		

		imguiCustom::Imgui_Render();
		glfwPollEvents();
		glfwSwapBuffers(windows);
	}
	

	renderer.Destroy();
	imguiCustom::Imgui_Destroy();
	glfwDestroyWindow(windows);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}