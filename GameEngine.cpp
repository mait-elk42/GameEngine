/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEngine.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:08:49 by mait-elk          #+#    #+#             */
/*   Updated: 2024/04/10 12:08:49 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GameEngine/GameEngine.hpp>

int main()
{
    GameContext context;

    context.Init()
            .WindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3)
            .WindowHint(GLFW_CONTEXT_VERSION_MINOR, 3)
            .WindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    context.OpenNewWindow(800, 600, "Game Engine Win1");
    

    glViewport(0, 0, 800, 600);
    while(context.Window_Is_Alive())
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        
        context.WindowSwapBuffers();
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}