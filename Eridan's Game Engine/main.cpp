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

#include "Engine/Renderer/OpenGL/ContextOpenGL.h"


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
	//CONTEXT
	ContextOpenGL context;
	context.CreateContext(800,600,"Eridan's Game Engine");
	//CAMERA
	Camera camera = Camera();
	//ENDERER
	Renderer renderer(context.GetWindow(), camera);

	imguiCustom::Imgui_Init(context.GetWindow());

	Square square;
	square.CreateQuad();
	square.CreateShader("Shader/texture2D.vert", "Shader/texture2D.frag", SHADER_3D_COLOR);
	square.shader.setVec3("ourColor", glm::vec3(0.5f, 1.0f, 1.0f));
	square.SetRotation(-89.f,glm::vec3(1.0f, 0.f, 0.f));
	square.SetPosition(glm::vec3(0,0,-0.5f));
	//square.SetTexture("Asset/Textures/wall.jpg");

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
	
	
	box2.shader.setVec3("lightColor", glm::vec3(1.0f,1.0f,1.0f));
	box2.shader.setVec3("lightPos", lightPos);
	box.shader.setVec3("lightColor", glm::vec3(1.0f,1.0f,1.0f));
	box.shader.setVec3("lightPos", lightPos);


	square.shader.setVec3("lightColor", glm::vec3(1.0f, 1.0f, 1.0f));
	square.shader.setVec3("lightPos", lightPos);
	square.SetScale(glm::vec3(10,10,0));

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_MULTISAMPLE);
	
	glfwSwapInterval(1);

	float deltaTime = 0.0f;
	float lastFrame = 0.0f;

	while (!glfwWindowShouldClose(context.GetWindow()))
	{
		glfwSetFramebufferSizeCallback(context.GetWindow(), framebuffer_size_callback);
		processInput(context.GetWindow());

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
		glfwSwapBuffers(context.GetWindow());
	}
	

	renderer.Destroy();
	imguiCustom::Imgui_Destroy();
	glfwDestroyWindow(context.GetWindow());
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