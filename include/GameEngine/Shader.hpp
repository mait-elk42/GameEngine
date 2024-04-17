/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shader.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 07:42:08 by mait-elk          #+#    #+#             */
/*   Updated: 2024/04/11 07:42:08 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADER_HPP
#define SHADER_HPP

#include <iostream>
#include <fstream> 
#include <string>

#define LOG(v) std::cout << v << std::endl;

#include <GameEngine/Vector3.hpp>
#include <GLFW/glfw3.h>
#include <glad/glad.h>

class ShaderProgram {
private:
	GLuint program;
public:
	ShaderProgram();
	~ShaderProgram();
	operator GLuint();
	ShaderProgram 	&Create();
	ShaderProgram	&AttachShader(GLuint ShaderType, std::string source_code);
	ShaderProgram	&AttachShaderFromFile(GLuint ShaderType, std::string filename);
	ShaderProgram	&SendUniformF(int location, Vector3 v3);
	GLint			GetUniformLocation(std::string name);
	void 			Use();
};

#endif