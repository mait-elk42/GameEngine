#include <iostream>
#include "include/GLFW/glfw3.h"

using namespace std;
int main()
{
    glfwInit();
    GLFWwindow *win = glfwCreateWindow(100, 100, "hello", NULL, NULL);
    cout << "hello" << endl;
    while (1);
}