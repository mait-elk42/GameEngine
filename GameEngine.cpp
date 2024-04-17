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


#error YOU SHOULD FIX MOUSE AXIS, PROJECTION , TRIANGLE AXIS
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
	VAO vao;
	VBO vbo;

	context.Init()
		.WindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3)
		.WindowHint(GLFW_CONTEXT_VERSION_MINOR, 3)
		.WindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE)
		.WindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, 1) // Transparent Window :0
		.OpenNewWindow(W, H, "Game Engine")
		.WinSetClearColor(127, 127, 127, 255);
	shader_program.Create()
		.AttachShaderFromFile(GL_VERTEX_SHADER, "Shaders/vert.glsl")
		.AttachShaderFromFile(GL_FRAGMENT_SHADER, "Shaders/frag.glsl")
		.Use();
	

	GLfloat vertices[] = {
		0.0f, 100.0f, 0.0f,  // Top
		100.0f, 0.0f, 0.0f,  // Bottom Right
	   -100.0f, 0.0f, 0.0f,  // Bottom Left
	};
	vao.Generate(1).Bind();
	vbo	.Generate(1).Bind(GL_ARRAY_BUFFER)
		.InitBuffer(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW)
		.SendData(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid *)0);

	GameObject obj;
	Transform &t = obj.transform;
	t.pivot = { 0.0f, -0.05f, 0.0f };
	t.position = {0.0f, 0.0f, 0.0f};

	// Vector3 projection = context.GetWinSize();
	Vector3 projection = {W, H, 1.0f};

	// loadTexture("t.jpg"); // trying To Add Texture In My Triangle
	while(context.Window_Is_Alive())
	{
		Vector2 fbs = context.GetFrameBufferSize();
		context.WinSetViewPort(0, 0, fbs.x, fbs.y);
		if (context.KeyStatus(GLFW_KEY_D) || context.KeyStatus(GLFW_KEY_A) || context.KeyStatus(GLFW_KEY_W) || context.KeyStatus(GLFW_KEY_S))
			LOG(t.position.x << ":" << t.position.y);
		t.position += {3.0f * context.KeyStatus(GLFW_KEY_D) + 3.0f * -context.KeyStatus(GLFW_KEY_A),
							   3.0f * context.KeyStatus(GLFW_KEY_W) + 3.0f * -context.KeyStatus(GLFW_KEY_S),
								0.0f};
		glClear(GL_COLOR_BUFFER_BIT);
		if (glfwGetMouseButton(context.GetWindowPtr(), GLFW_MOUSE_BUTTON_LEFT))
		{
			Vector2 mp = context.GetMousePosition();
			mp.y = -mp.y;
			LOG("MPX: " << mp.x << " : MPY: " << mp.y << "\t POSX : " << t.position.x << " : POSY :" << t.position.y);
		}
		shader_program.SendUniformF(shader_program.GetUniformLocation("position"), t.position);
		shader_program.SendUniformF(shader_program.GetUniformLocation("rotation"), t.rotation);
		shader_program.SendUniformF(shader_program.GetUniformLocation("scale"), t.scale);
		shader_program.SendUniformF(shader_program.GetUniformLocation("pivot"), t.pivot);
		glUniform3f(glGetUniformLocation(shader_program, "projection"), projection.x, projection.y, projection.z);
        glDrawArrays(GL_TRIANGLES, 0, 3);
		if (context.KeyStatus(GLFW_KEY_ESCAPE))
			break;
		context.WindowSwapBuffers();
		glfwPollEvents();
	}
	return 0;
}