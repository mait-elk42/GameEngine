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

#define W 1200
#define H 700

GLuint textureID; // Texture ID

// Load texture function
// void loadTexture(const char* texturePath) {
//     int width, height, channels;
//     unsigned char* data = stbi_load(texturePath, &width, &height, &channels, 0);
//     glGenTextures(1, &textureID);
//     glBindTexture(GL_TEXTURE_2D, textureID);
//     // Set texture parameters
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//     // Transfer texture data to GPU
//     if (data) {
//         glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//         glGenerateMipmap(GL_TEXTURE_2D);
//     } else {
//         printf("Failed to load texture\n");
//     }
//     stbi_image_free(data);
// }

int main()
{
	GameContext context;
	ShaderProgram shader_program;
	VAO vao, vao2;
	VBO vbo, vbo2;

	context.Init()
		.WindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3)
		.WindowHint(GLFW_CONTEXT_VERSION_MINOR, 3)
		.WindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE)
		// .WindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, 1) // Transparent Window :0
		.OpenNewWindow(W, H, "Game Engine")
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

	vao2.Generate(1).Bind();
	vbo2	.Generate(1).Bind(GL_ARRAY_BUFFER)
		.InitBuffer(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW)
		.SendData(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid *)0);
	
	Vector3 objpos = { 0.3f, 0.1f, 0.0f };
	Vector3 objscale = { 1.0f, 1.0f, 1.0f };
	Vector3 objpivot = { 0.0f, -0.05f, 0.0f };

	context.WinSetViewPort(0, 0, W * 2, H * 2);

	float angle = 0.0f;
	// loadTexture("t.jpg"); // trying To Add Texture In My Triangle
	while(context.Window_Is_Alive())
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glUniform3f(glGetUniformLocation(shader_program, "position"), objpos.x, objpos.y, objpos.z);
		glUniform3f(glGetUniformLocation(shader_program, "scale"), objscale.x, objscale.y, objscale.z);
		glUniform3f(glGetUniformLocation(shader_program, "pivot"), objpivot.x, objpivot.y, objpivot.z);
		glUniform1f(glGetUniformLocation(shader_program, "angle"), angle);
        glDrawArrays(GL_TRIANGLES, 0, 3);
		objpos.x += 0.01f * (context.KeyStatus(GLFW_KEY_D));
		objpos.x -= 0.01f * (context.KeyStatus(GLFW_KEY_A));
		objpos.y += 0.01f * (context.KeyStatus(GLFW_KEY_W));
		objpos.y -= 0.01f * (context.KeyStatus(GLFW_KEY_S));

		angle -= 0.1f;
		if (context.KeyStatus(GLFW_KEY_ESCAPE))
			break;
		context.WindowSwapBuffers();
		glfwPollEvents();
	}
	return 0;
}