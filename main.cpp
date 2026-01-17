#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main()
{
	glfwInit();
	//we run glfw with glfwinit to initialize the library
	


	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwwindowhint tells us what option we want to configure where we can select the options
	// from a large list/enum of options beginning with GLFW_


	GLFWwindow* window = glfwCreateWindow(800, 600, "opengl", NULL, NULL);
	if (window == NULL)
		//creates the window object, the window object holds the information about the window
		//
	{
		std::cout << "failed to create window" << std::endl;
		return -1;
	}

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		//this manages function pointers for opengl
		//we pass the glad function to load the addr of the onegl function pointers which is OS-specific
		//GLFW gives us glfwgetprocaddress that defined the correct function based on the OS we are using/compiling for

	{
		std::cout << "failed to run glad" << std::endl;
		return -1;

	}

	glViewport(0, 0, 800, 6000);
	// first coords are the lower left corner of the window
	// second two are the width and height of the window in pixels
	//we have to tell opengl the sizae of the rendering window so opengl knows how we want to display the data and coords with respect to the window
	//for example a processed point of location(-0.5, 0.5) would(as its final transformation be mapped to (200,450) in screen coords.
	//coords in opengl range from -1 and 1 so we map from the range(-1,1) to (0,800) and (0,600)

	// we can add a callback function that gets called everytime the window is resized

	void framebuffer_size_callback(GLFWwindow * window, int width, int height);
	{
		glViewport(0, 0, width, height);

	}
	// we do have to tell glfw we want to call this function on every window resize(you register it)
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	return 0;
}
