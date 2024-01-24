#include <stdio.h>
#include<GL/glew.h>
#include<GLFW/glfw3.h>
using namespace std;

//Window Dimension
const GLint WIDTH = 800, HEIGHT = 600;


int main(){

	if (!glfwInit()) {
		printf("GLFW Initialization Failed");
		glfwTerminate();
		return 1;
	}
	// setup GLFW window properties
	// OpenGL version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Core Profile = No Backwards Compatibility
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// Allow forward compatibilty 
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);


	GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "TEST WINDOW", NULL, NULL);

	if (!mainWindow) {
		printf("GLFW Window creation failed");
		glfwTerminate();
		return 1;
	}

	// Get buffer size information
	int bufferWidth, bufferHeight;
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

	// Set Context for GLEW to use
	glfwMakeContextCurrent(mainWindow);

	// Allow Modern extension features
	glewExperimental = GL_TRUE;
	if (glewInit()!=GLEW_OK) {

		printf("GLEW Initialization failed.");
		glfwDestroyWindow(mainWindow);
		glfwTerminate;
		return 1;
	}

	// Setup ViewPort Size
	glViewport(0, 0, bufferWidth, bufferHeight);
	//Loop until window closed
	while (!glfwWindowShouldClose(mainWindow)) {

		// Get + Handle User Input events
		glfwPollEvents();
		// Clear Window
		glClearColor(1.0f, 0.5f, 0.0f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(mainWindow);

	}

	
return 0;

}
