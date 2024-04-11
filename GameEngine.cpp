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

// Vertex shader source code
std::string vertexShaderSource = R"glsl(
    #version 330 core
    layout (location = 0) in vec3 position;
    void main() {
        gl_Position = vec4(position.x, position.y, position.z, 1.0);
    }
)glsl";

// Fragment shader source code
std::string fragmentShaderSource = R"glsl(
    #version 330 core
    out vec4 color;
    void main() {
        color = vec4(1.0f, 1.0f, 1.0f, 1.0f);
    }
)glsl";

int main()
{
    GameContext context;

    context.Init()
            .WindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3)
            .WindowHint(GLFW_CONTEXT_VERSION_MINOR, 3)
            .WindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    context.OpenNewWindow(800, 600, "Game Engine Win1");
    

    ShaderProgram program;
    glViewport(0, 0, 800, 600);

    program.AttachShader(GL_VERTEX_SHADER, vertexShaderSource);
    program.AttachShader(GL_FRAGMENT_SHADER, fragmentShaderSource);

    GLfloat vertices[] = {
         0.5f,  0.5f, 0.0f,  // Top Right
         0.5f, -0.5f, 0.0f,  // Bottom Right
        -0.5f, -0.5f, 0.0f,  // Bottom Left
    };
     GLuint VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glGenBuffers(1, &VBO);
    
    LOG("VAO " << VAO << " | VBO " << VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    // glBindVertexArray(0);

    while(context.Window_Is_Alive())
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        program.Use();
        // glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        // glBindVertexArray(0);
        context.WindowSwapBuffers();
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}