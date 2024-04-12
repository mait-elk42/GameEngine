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
	GameContext	&WinSetClearColor(GLchar red, GLchar green, GLchar blue, GLchar alpha);
	GameContext &WindowHint(int hint, int value);
	GameContext	&WinSetViewPort(GLint x, GLint y, GLsizei width, GLsizei height);
	GameContext	&OpenNewWindow(int width, int height, std::string title);
};

#endif