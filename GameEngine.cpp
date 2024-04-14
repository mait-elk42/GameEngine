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

#include <cmath>

typedef struct s_vector3f
{
	float	x = 0.0f;
	float	y = 0.0f;
	float	z = 0.0f;
}	t_vector3f;

int main()
{
	GameContext context;
	ShaderProgram shader_program;
	VAO vao;
	VBO vbo;

	context.Init()
		.WindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3)
		.WindowHint(GLFW_CONTEXT_VERSION_MINOR, 3)
		.WindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE)
		// .WindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, 1) // Transparent Window :0
		.OpenNewWindow(800, 600, "Game Engine")
		.WinSetClearColor(127, 127, 127, 255);
	shader_program.Create()
		.AttachShaderFromFile(GL_VERTEX_SHADER, "Shaders/vert.glsl")
		.AttachShaderFromFile(GL_FRAGMENT_SHADER, "Shaders/frag.glsl")
		.Use();
	

	GLfloat vertices[] = {
		0.0f, 0.1f, 0.0f,  // Top Right
		0.1f, 0.0f, 0.0f,  // Bottom Right
	   -0.1f, 0.0f, 0.0f,  // Bottom Left
	};
	vao.Generate(1).Bind();
	vbo	.Generate(1).Bind(GL_ARRAY_BUFFER)
		.InitBuffer(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW)
		.SendData(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid *)0);

	t_vector3f objpos = { 0.3f, 0.1f, 0.0f };
	t_vector3f objrot = { 0.3f, 0.1f, 0.0f };
	t_vector3f objscale = { 3.0f, 3.0f, 3.0f };
	t_vector3f objpivot = { 0.0f, -0.05f, 0.0f };
	// float angle = 0.0f;
	while(context.Window_Is_Alive())
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glUniform3f(glGetUniformLocation(shader_program, "position"), objpos.x, objpos.y, objpos.z);
		glUniform3f(glGetUniformLocation(shader_program, "scale"), objscale.x, objscale.y, objscale.z);
		glUniform3f(glGetUniformLocation(shader_program, "rotation"), objrot.x, objrot.y, objrot.z);
		glUniform3f(glGetUniformLocation(shader_program, "pivot"), objpivot.x, objpivot.y, objpivot.z);
		// glUniform1f(glGetUniformLocation(shader_program, "angle"), angle);
        glDrawArrays(GL_TRIANGLES, 0, 3);
		context.WindowSwapBuffers();
		if (context.KeyStatus(GLFW_KEY_D))
			objpos.x += 0.01f;
		if (context.KeyStatus(GLFW_KEY_A))
			objpos.x += -0.01f;
		if (context.KeyStatus(GLFW_KEY_W))
			objpos.y += 0.01f;
		if (context.KeyStatus(GLFW_KEY_S))
			objpos.y += -0.01f;

		// if (context.KeyStatus(GLFW_KEY_D))
		// 	angle += -0.02f;
		// if (context.KeyStatus(GLFW_KEY_A))
			// angle += -0.02f;
		glfwPollEvents();
	}
	return 0;
}