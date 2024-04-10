#include <GameEngine/System/GameContext.hpp>

GameContext::GameContext()
{

}

GameContext::~GameContext()
{
	
}

GameContext	GameContext::Init()
{
	if (!glfwInit())
	{
		LOG ("Failed to Init GLFW");
    	exit (-1);
	}
	LOG("GLFW INITIALIZED");
	return (*this);
}

int	GameContext::Window_Is_Alive()
{
	return (!glfwWindowShouldClose(this->window_ptr));
}

GameContext GameContext::WindowSwapBuffers()
{
	glfwSwapBuffers(this->window_ptr);
	return (*this);
}

GameContext GameContext::WindowHint(int hint, int value)
{
    glfwWindowHint(hint, value);
	return (*this);
}

GameContext GameContext::OpenNewWindow(int width, int height, std::string title)
{
	this->window_ptr = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
	if (this->window_ptr == nullptr)
	{
		LOG ("Failed to create GLFW Window :(");
        glfwTerminate();
        exit (-1);
	}
    glfwMakeContextCurrent(this->window_ptr);
	LOG ("WINDOW OPENED :)");
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        LOG ("Failed to initialise GLAD :(");
    }
	LOG("GLAD INITIALIZED :)");
	return (*this);
}