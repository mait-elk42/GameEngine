#include <GameEngine/GameContext.hpp>

GameContext::GameContext()
{

}

GameContext::~GameContext()
{
	glfwTerminate();
}

GameContext	&GameContext::Init()
{
	if (!glfwInit())
	{
		LOG ("Failed to Init GLFW :(");
    	exit (-1);
	}
	LOG("\033[32m""GLFW INITIALIZED :)""\033[0m");
	return (*this);
}

int	GameContext::Window_Is_Alive()
{
	return (!glfwWindowShouldClose(this->window_ptr));
}

GameContext &GameContext::WindowSwapBuffers()
{
	glfwSwapBuffers(this->window_ptr);
	return (*this);
}

GameContext	&GameContext::WinSetClearColor(GLchar red, GLchar green, GLchar blue, GLchar alpha)
{
	GLfloat	redNormalized = (GLfloat) ((unsigned char)red) / 255.0f;
	GLfloat	greenNormalized = (GLfloat) ((unsigned char)green) / 255.0f;
	GLfloat	blueNormalized = (GLfloat) ((unsigned char)blue) / 255.0f;
	GLfloat	alphaNormalized = (GLfloat) ((unsigned char)alpha) / 255.0f;

	LOG (redNormalized  << ":" << greenNormalized << ":" << blueNormalized << ":" << alphaNormalized);
    glClearColor(redNormalized, greenNormalized, blueNormalized, alphaNormalized);
    return (*this);
}

GameContext &GameContext::WindowHint(int hint, int value)
{
    glfwWindowHint(hint, value);
	return (*this);
}

GameContext &GameContext::OpenNewWindow(int width, int height, std::string title)
{
	this->window_ptr = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
	if (this->window_ptr == nullptr)
	{
		LOG ("Failed to create GLFW Window :(");
        glfwTerminate();
        exit (-1);
	}
    glfwMakeContextCurrent(this->window_ptr);
	LOG ("\033[32m""WINDOW OPENED :)""\033[0m");
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        LOG ("Failed to initialise GLAD :(");
    }
	LOG("\033[32m""GLAD INITIALIZED :)""\033[0m");
	WinSetViewPort(0, 0, width, height);
	return (*this);
}

GameContext	&GameContext::WinSetViewPort(GLint x, GLint y, GLsizei width, GLsizei height)
{
	glViewport(x, y, width, height);
	return (*this);
}