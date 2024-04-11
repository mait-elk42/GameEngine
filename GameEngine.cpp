/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   GameEngine.cpp									 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mait-elk <mait-elk@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/04/10 12:08:49 by mait-elk		  #+#	#+#			 */
/*   Updated: 2024/04/10 12:08:49 by mait-elk		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <GameEngine/GameEngine.hpp>

int main()
{
	GameContext context;
	context.Init()
		   .WindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3)
		   .WindowHint(GLFW_CONTEXT_VERSION_MINOR, 3)
		   .WindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE)
		   .OpenNewWindow(800, 600, "Game Engine")
		   .WinSetViewPort(0, 0, 800, 600);
	
	context.shader_program.Create()
		   .AttachShader(GL_VERTEX_SHADER, R"glsl(
					#version 330 core
					layout (location = 0) in vec3 position;
					void main() {
						gl_Position = vec4(position.x, position.y, position.z, 1.0);
					}
				)glsl")
		   .AttachShader(GL_FRAGMENT_SHADER, R"glsl(
					#version 330 core
					out vec4 color;
					void main() {
						color = vec4(0.5f, 1.0f, 1.0f, 1.0f);
					}
				)glsl");

	context.gpu_memory.GenVAO()
					  .GenVBO()
					  .BindVAO()
					  .BindVBO();


	GLfloat vertices[] = {
		0.0f,  0.5f, 0.0f,  // Top Right
		0.5f, 0.0f, 0.0f,  // Bottom Right
		-0.5f, 0.0f, 0.0f,  // Bottom Left
	};
	context.gpu_memory.SetData(sizeof(vertices), vertices, GL_STATIC_DRAW);
	context.gpu_memory.SetAttribute(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	while(context.Window_Is_Alive())
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		context.shader_program.Use();
		context.gpu_memory.BindVAO();
		glDrawArrays(GL_TRIANGLES, 0, 3);
		context.WindowSwapBuffers();
		glfwPollEvents();
	}
	return 0;
}