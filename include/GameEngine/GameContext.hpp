/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameContext.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:11:46 by mait-elk          #+#    #+#             */
/*   Updated: 2024/04/10 12:11:46 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_CONTEXT_HPP
#define GAME_CONTEXT_HPP

#define LOG(v) std::cout << v << std::endl;

#include <GameEngine/Shader.hpp>
#include <GameEngine/Vector2.hpp>
#include <GameEngine/Vector3.hpp>
#include <iostream>
#include <string>

#include <GLFW/glfw3.h>
// #include <glad/glad.h>

class GameContext {
private:
    GLFWwindow	*window_ptr;
public:
	GameContext();
	~GameContext();
	int	Window_Is_Alive();
	GameContext	&Init();
	GameContext &WindowSwapBuffers();
	int			KeyStatus(int key);
	GLFWwindow	*GetWindowPtr();
	Vector2		GetMousePosition();
	Vector2		GetWinSize();
	Vector2		GetFrameBufferSize();
	GameContext &WindowHint(int hint, int value);
	GameContext	&OpenNewWindow(int width, int height, std::string title);
	GameContext	&WinSetViewPort(GLint x, GLint y, GLsizei width, GLsizei height);
	GameContext	&WinSetClearColor(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha);
};

#endif