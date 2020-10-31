#include "ContextOpenGL.h"

ContextOpenGL::ContextOpenGL() : window(nullptr)
{
	
	

	
}

ContextOpenGL::~ContextOpenGL()
{
}

int ContextOpenGL::errorContext()
{
	return 0;
}

void ContextOpenGL::CreateContext(float width, float height, const char* title)
{
	glfwSetErrorCallback(glfw_error_callback);
	if (!glfwInit())
	{
		std::cout << "ERROR::INIT::GLFW /n";
	}
	openglHintDefault();

	window = glfwCreateWindow(width, height, title, NULL, NULL);
	this->width = width;
	this->height = height;
	this->title = title;

	if (!window)
	{
		std::cout << "ERROR:CREATE::WINDOW /n";
	}

	glfwMakeContextCurrent(window);

	initGlad();
}

void ContextOpenGL::openglHintDefault()
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);
}

int ContextOpenGL::initGlad()
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD /n";
		return -1;
		exit(EXIT_FAILURE);
	}
}
